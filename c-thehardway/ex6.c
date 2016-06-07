#include <stdio.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[]= "Ted";
    char last_name[]="Shaw";
    int len = 2;

    printf("You are %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super powers.\n", super_power);
    printf("You have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s. \n", last_name);
    printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);
    printf("");
    printf("There have been printed some number of chars.%n \n",&len);
    printf("some equals %d.\n", len);

    return 0;
}