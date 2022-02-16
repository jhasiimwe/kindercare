#include <stdio.h>
#include <string.h>
int main() {
char command[100];
puts("Enter command:");
gets(command);
char assignmentId[5];
strcpy(assignmentId,command+15);
puts(assignmentId);
//viewassignment
}