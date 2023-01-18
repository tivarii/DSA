#include <stdio.h>
#include <stdlib.h>
struct node
{
  int degree, coef;
  struct node *next;
};

void insert(struct node **h, int deg, int coeff)
{
  struct node *temp;
  temp = *h;
  struct node *prev = temp;
  if (temp)
  {
    while (temp != NULL)
    {
      if (temp->degree <= deg)
      {
        if (temp->degree == deg)
        {
          temp->coef += coeff;
          return;
        }
        break;
      }
      prev = temp;
      temp = temp->next;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->coef = coeff;
    ptr->degree = deg;
    ptr->next = temp;
    if (temp == *h)
    {
      *h = ptr;
    }
    else
      prev->next = ptr;
  }
  else
  {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->coef = coeff;
    ptr->degree = deg;
    ptr->next = NULL;
    *h = ptr;
  }
}

void showPoly(struct node *h)
{
  if (h)
  {
    while (h != NULL)
    {
      printf("%dX^%d", h->coef, h->degree);
      if (h->next && h->next->coef > 0)
      {
        printf("+");
      }
      h = h->next;
    }
  }
}

void polyadd(struct node *p1, struct node *p2, struct node **result)
{
  // printf("\nyha");
  while (p1 && p2)
  {
    if (p1->degree > p2->degree)
    {
      insert(&(*result), p1->degree, p1->coef);
      p1 = p1->next;
    }
    else if (p1->degree < p2->degree)
    {
      insert(&(*result), p2->degree, p2->coef);
      p2 = p2->next;
    }
    else
    {
      insert(&(*result), p2->degree, (p2->coef + p1->coef));
      p1 = p1->next;
      p2 = p2->next;
    }
  }
  while (p1 || p2)
  {
    if (p1)
    {
      insert(&(*result), p1->degree, p1->coef);
      p1 = p1->next;
    }
    else if (p2)
    {
      insert(&(*result), p2->degree, p2->coef);
      p2 = p2->next;
    }
  }
}
int main()
{
  struct node *poly1 = NULL;
  printf("enter 1st polynmial.\n");
  int cond = 1;
  while (cond)
  {
    int d, c;
    printf("enter coefficient: ");
    scanf("%d", &c);
    printf("enter degree: ");
    scanf("%d", &d);
    if (d < 0)
    {
      printf("Degree can never be negative");
      continue;
    }
    insert(&poly1, d, c);
    printf("enter 0 to enter next polynomial and else to enter more in same polynomial: ");
    scanf("%d", &cond);
  }
  showPoly(poly1);

  struct node *poly2 = NULL;
  printf("\nenter 2nd polynomial.\n");
  cond = 1;
  while (cond)
  {
    int d, c;
    printf("enter coefficient: ");
    scanf("%d", &c);
    printf("enter degree: ");
    scanf("%d", &d);
    if (d < 0)
    {
      printf("\nDegree can never be negative.\n");
      continue;
    }
    insert(&poly2, d, c);
    printf("enter 0 to enter next polynomial and else to add both polynomial: ");
    scanf("%d", &cond);
  }
  showPoly(poly2);
  
  printf("\n+\n");
  showPoly(poly1);
  struct node *result = NULL;
  polyadd(poly1, poly2, &result);
  printf("\n=\n");
  showPoly(result);
}