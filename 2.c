#include <stdio.h>
#include<stdlib.h>

struct element{
    int i;
    int j;
    int x;
};

struct sparse{
    int m;
    int n;
    int num;
    struct element* ele;
};

void create(struct sparse *s){
    printf("Enter the dimension of the matrix: ");
    scanf("%d %d", &s->m,&s->n);
    printf("Number of non zero element: ");
    scanf("%d",&s->num);
    s->ele = (struct element*)malloc(s->num * sizeof(struct element));
    printf("Enter the non zero elements: ");
    for(int i = 0; i < s->num; i++){
            scanf("%d %d %d",&s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
        
    }
                                     
}

void display(struct sparse *s){
    int k = 0;
    for(int i = 0; i < s->m; i++){
        for(int j = 0; j < s->n; j++){
            if(i==s->ele[k].i && j==s->ele[k].j){
                printf("%d ",s->ele[k++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct sparse* add(struct sparse *s1, struct sparse *s2){
   
    if(s1->m != s2->m && s1->n != s2->n){
        printf("Addition cannot be happen!!");
        return NULL;
    }
    struct sparse *s;
    int i, j, k;
    i = j = k = 0;
    s = (struct sparse*)malloc(sizeof(struct sparse));
    s->m = s1->m;
    s->n = s1->n;
    s->ele = (struct element*)malloc((s1->num + s2->num) * sizeof(struct element));
   
    while(i < s1->num && j < s2->num){
        if(s1->ele[i].i < s2->ele[i].i){
            s->ele[k++] = s1->ele[i++];
        }
        else if(s1->ele[i].i > s2->ele[j].i){
            s->ele[k++] = s1->ele[j++];
        }
        else {
            if(s1->ele[i].j < s2->ele[j].j){
                s->ele[k++] = s1->ele[i++];
            }
            else if(s1->ele[i].j > s2->ele[j].j){
                s->ele[k++] = s2->ele[j++];
            }
            else{
                s->ele[k] = s1->ele[i];
                s->ele[k].x = s1->ele[i].x + s2->ele[j].x;
            }
        }
    }
    
    while(i < s1->num){
        s->ele[k++] = s1->ele[i++];
    }
    
    while(j < s2->num){
        s->ele[k++] = s2->ele[j++];
    }
    s->num = k;
    
    return s;
    
}



int main(int argc, const char * argv[]) {
    struct sparse s1, s2, *s;
 
    
    create(&s1);
    display(&s1);
    create(&s2);
    display(&s2);
    s = add(&s1, &s2);
    printf("\n");
    display(s);
    
    free(s->ele);
    
    return 0;
}
