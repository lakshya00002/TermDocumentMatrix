#include <stdio.h>
#include <stdlib.h>

struct termdocument
{
    int **ptr;
    int num_term;
    int num_doc;
};

struct termdocument *createTernDocumentMatrix(struct termdocument *m1, int num_term, int num_doc)
{
    m1->ptr = (int **)malloc(num_doc * sizeof(int *));
    for (int i = 0; i < num_doc; i++)
    {
        m1->ptr[i] = (int *)malloc(num_term * sizeof(int));
    }
    m1->num_term = num_term;
    m1->num_doc = num_doc;
    return m1;
}

void updateTermFrequency(struct termdocument *m1, int term, int doc, int val)
{
    if (term < m1->num_term && doc < m1->num_doc)
    {
        m1->ptr[term][doc] = val;
    }
    else
    {
        printf("please enter valid index of document or term\n");
    }
}

int getTermFrequency(struct termdocument *m1, int term, int doc)
{
    if (term < m1->num_term && doc < m1->num_doc)
    {
        return m1->ptr[term][doc];
    }
    else
    {
        printf("please enter valid index of document or term\n");
    }
}

int main()
{
    struct termdocument m;
    int choice, num_term, num_doc, term, doc, val;

    printf("Enter the number of terms: ");
    scanf("%d", &num_term);
    printf("Enter the number of documents: ");
    scanf("%d", &num_doc);

    createTernDocumentMatrix(&m, num_term, num_doc);

    do
    {
        printf("\nMenu:\n");
        printf("1. Update Term Frequency\n");
        printf("2. Get Term Frequency\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter term index: ");
            scanf("%d", &term);
            printf("Enter document index: ");
            scanf("%d", &doc);
            printf("Enter value: ");
            scanf("%d", &val);
            updateTermFrequency(&m, term, doc, val);
            break;
        case 2:
            printf("Enter term index: ");
            scanf("%d", &term);
            printf("Enter document index: ");
            scanf("%d", &doc);
            printf("Term frequency: %d\n", getTermFrequency(&m, term, doc));
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 0);

    for (int i = 0; i < num_doc; i++)
    {
        free(m.ptr[i]);
    }
    free(m.ptr);

    return 0;
}
