// tail.c
// Riesenie IJC-DU2, príklad 1a), 25.4.2016
// Autor:     Daniel Klimaj, FIT
// Prelozene: gcc 5.3.0
// Program na citanie poslednych n riadkov suboru

#include "tail.h"

/**
 * Main.
 * @param argc Pocet argumentov
 * @param argv Zoznam argumentov
 * @return EXIT_SUCCES v priade uspechu, inak EXIT_FAILURE
 */
int main(int argc, char **argv)
{
    String file_name;
    strInit(&file_name, NULL);
    int n;

    if(argc == 1)
    {
        n = 10;
    }
    else if(argc == 2)
    {
        strSet(&file_name, argv[1]);
        n = 10;
    }
    else if(argc == 3 || argc == 4)
    {
        if(strcmp(argv[1], "-n") == 0)
        {
            for(unsigned i=0; i<strlen(argv[2]); i++)
            {
                if(!isdigit(argv[2][i]))
                {
                    fprintf(stderr,"Invalid format of number of lines\n");
                    return EXIT_FAILURE;
                }
            }
            n = atoi(argv[2]);
        }
        else
        {
            fprintf(stderr,"Invalid argument %s\n", argv[1]);
            return EXIT_FAILURE;
        }

        if(argc == 4)
            strSet(&file_name, argv[3]);
    }
    else
    {
        fprintf(stderr,"Invalid number of arguments\n");
        return EXIT_FAILURE;
    }

    int rslt = read_stream(file_name, n);

    return rslt;
}

/**
 * Otvorenie streamu pre citanie riadkov. Ak je file_name prazdny retazec,
 * pouzije sa stdin.
 * @param file_name Nazov suboru
 * @param count Maximalny pocet citanych riadkov
 * @return EXIT_SUCCES v priade uspechu, inak EXIT_FAILURE
 */
int read_stream(String file_name, int count)
{
    FILE *f;
    int rslt;

    if(strCmp(file_name, "") == 0)
    {
        f = stdin;
        rslt = read_lines(f, count);
    }
    else
    {
        f = fopen(str(file_name), "r");
        if(f != NULL)
        {
            rslt = read_lines(f, count);
            fclose(f);
        }
        else
        {
            fprintf(stderr,"Failed to open file '%s'\n", str(file_name));
            return EXIT_FAILURE;
        }
    }

    return rslt;
}

/**
 * Citanie riadkov.
 * @param f Subor, z ktoreho sa cita
 * @param count Maximalny pocet citanych riadkov
 * @return EXIT_SUCCES v priade uspechu, inak EXIT_FAILURE
 */
int read_lines(FILE *f, int count)
{
    char c;
    String s;
    StringList sl;
    strInit(&s, NULL);
    slInit(&sl, 0);
    int rslt = EXIT_SUCCESS;

    while((c = fgetc(f)) != EOF)
    {
        if(rslt == EXIT_SUCCESS)
        {
            if(c == '\n')
            {
                rslt = slAppendS(&sl, s);
                if(rslt == EXIT_SUCCESS)
                {
                    rslt = strSet(&s, "");
                }
            }
            else
            {
                rslt = strAppendC(&s, c);
            }
        }

        if(rslt == EXIT_FAILURE)
        {
            break;
        }
    }

    // Poledny riadok
    rslt = slAppendS(&sl, s);

    if(rslt == EXIT_SUCCESS)
    {
        int lines = slLen(&sl);
        if(count > lines)
        {
            count = lines;
        }

        for(int i=(lines-count), j=1; i<lines; i++, j++)
        {
            String *tmp = slAt(&sl, i);
            printf("%s\n", str(*tmp));
        }
    }
    else
    {
        fprintf(stderr,"Failed to read lines from file\n");
    }

    slFree(&sl);
    strFree(&s);
    return rslt;
}

// String

/**
 * Inicializacia retazca.
 * @param s Inicializovany retazec
 * @param cstr Hodnota, na ktoru sa inicializuje, ak je NULL, tak sa
 * inicializuje na prazdny retazec
 * @return EXIT_SUCCES v priade uspechu, inak EXIT_FAILURE
 */
int strInit(String *s, const char *cstr)
{
    int len = (cstr != NULL) ? strlen(cstr) : 0;

    if((s->str = (char*)malloc(len+1)) == NULL)
    {
        return EXIT_FAILURE;
    }
    else
    {
        s->len = len;
        if(cstr != NULL)
            strcpy(s->str, cstr);
        s->str[len] = '\0';
    }
    return EXIT_SUCCESS;
}

/**
 * Pripojenie znaku na koniec retazca.
 * @param s Retazec
 * @param c Znak
 * @return EXIT_SUCCES v priade uspechu, inak EXIT_FAILURE
 */
int strAppendC(String *s, char c)
{
    if(s->str != NULL)
    {
        if((s->str = (char*)realloc(s->str, s->len+2)) != NULL)
        {
            s->str[s->len] = c;
            s->len++;
            s->str[s->len] = '\0';
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

/**
 * Pripojenie retazca na koniec retazca.
 * @param s Retazec
 * @param cstr Pripajany retazec
 * @return EXIT_SUCCES v priade uspechu, inak EXIT_FAILURE
 */
int strAppendS(String *s, const char *cstr)
{
    int rslt;
    if(s->str != NULL)
    {
        int len = strlen(cstr) + s->len;
        char *ns = (char*)malloc(len+1);
        strcpy(ns, s->str);
        strcat(ns, cstr);
        rslt = strSet(s, ns);
        free(ns);
    }
    else
    {
        rslt = strInit(s, cstr);
    }
    return rslt;
}

/**
 * Nastavenie retazca na inu hodnotu.
 * @param s Retazec
 * @param cstr Hodnota, na ktoru sa nastavuje
 * @return EXIT_SUCCES v priade uspechu, inak EXIT_FAILURE
 */
int strSet(String *s, const char *cstr)
{
    strFree(s);
    return strInit(s, cstr);
}

/**
 * Porovnanie retazca s c-retazcom.
 * @param s Retazec
 * @param cstr C-retazec
 * @return 0, 1 alebo -1 (@see strcmp)
 */
int strCmp(String s, const char *cstr)
{
    return strcmp(s.str, cstr);
}

/**
 * Zrusenie retazca.
 * @param s Ruseny retazec
 */
void strFree(String *s)
{
    if(s->str != NULL)
        free(s->str);

    s->str = NULL;
    s->len = 0;
}

/**
 * Hodnota retazca.
 * @param s Retazec
 * @return Aktualnu hodnotu retazca
 */
char* str(String s)
{
    return (s.str == NULL) ? "" : s.str;
}

/**
 * Dlzka retazca.
 * @param s Retazec
 * @return Aktualnu dlzku retazca
 */
unsigned strLen(String s)
{
    return (s.str == NULL) ? 0 : s.len;
}

// StringList

/**
 * Inicializacia zoznamu retazcov na danu velkost.
 * @param l Zoznam retacov
 * @param size Pociatocna velkost zoznamu
 * @return EXIT_SUCCES v priade uspechu, inak EXIT_FAILURE
 */
int slInit(StringList *l, unsigned size)
{
    if(size > 0)
    {
        if((l->arr = malloc(size * sizeof(String))) != NULL)
        {
            for(unsigned i=0; i<size; i++)
            {
                strInit(&(l->arr[i]), "");
            }
        }
        else
        {
            return EXIT_FAILURE;
        }
    }
    else
    {
        l->arr = NULL;
    }
    l->len = size;
    return EXIT_SUCCESS;
}

/**
 * Retazec ulozeny na danej pozicii.
 * @param l Zoznam retacov
 * @param index Index pozadovaneho retazca
 * @return Retazec alebo NULL
 */
String *slAt(StringList *l, unsigned index)
{
    if(index <= l->len)
    {
        return &(l->arr[index]);
    }
    else
    {
        fprintf(stderr,"slSetAt: Index %d out of range!\n", index);
        return NULL;
    }
}

/**
 * Pridanie retazca na koniec zoznamu.
 * @param l Zoznam retacov
 * @param s Ukladany retazec
 * @return EXIT_SUCCES v priade uspechu, inak EXIT_FAILURE
 */
int slAppendS(StringList *l, String s)
{
    if(l->len > 0)
    {
        if((l->arr = realloc(l->arr, (l->len+1) * sizeof(String))) != NULL)
        {
            strInit(&(l->arr[l->len]), str(s));
            l->len++;
        }
        else
        {
            return EXIT_FAILURE;
        }
    }
    else
    {
        slInit(l, 1);
        strSet(&(l->arr[0]), str(s));
    }
    return EXIT_SUCCESS;
}

/**
 * Dlzka zoznamu retazcov.
 * @param s Zoznam retazcov
 * @return Aktualnu dlzku zoznamu
 */
unsigned slLen(StringList *l)
{
    return l->len;
}

/**
 * Zrusenie zoznamu retazcov.
 * @param s Zoznam retazcov
 */
void slFree(StringList *l)
{
    for(unsigned i=0; i<l->len; i++)
    {
        strFree(&(l->arr[i]));
    }
    free(l->arr);
    l->arr = NULL;
    l->len = 0;
}
