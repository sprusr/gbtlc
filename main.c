#include <gb/gb.h>
#include <stdio.h>
#include <gb/console.h>
#include <string.h>

#include "savevars.h"

#define INPUT_DELAY 200

char s[60] = "";
char topMessage[60] = "";

int menuIndex = 0;
char *menuItems[3] = {"View todos", "Add todo", "Switch user"};

int todoCount = 0;
char *todos[30];

int i;
char c;

void drawMenu()
{
  if(topMessage != "") {
    printf("%s\n", topMessage);
  }

  strncpy(topMessage, "", 60);

  for (i = 0; i < 3; i++) {
    if(i == menuIndex) {
      printf("> %s\n", menuItems[i]);
    } else {
      printf("  %s\n", menuItems[i]);
    }
  }
}

void initMenu()
{
  sprintf(topMessage, "Welcome, %s\n", username);
  menuIndex = 0;
  drawMenu();
}

void moveDown()
{
  menuIndex = (menuIndex + 1) % 3;
  drawMenu();
}

void moveUp()
{
  if(menuIndex == 0) {
    menuIndex = 2;
  } else {
    menuIndex = (menuIndex - 1) % 3;
  }

  drawMenu();
}

void viewTodos()
{
  cls();
  puts("\n");
  for (i = 0; i < todoCount; i++) {
    printf(" - %s\n", todos[i]);
  }
  drawMenu();
}

void addTodo()
{
  puts("Enter todo:");
  gets(s);
  todos[todoCount] = s;
  todoCount++;
  drawMenu();
}

void switchUser()
{
  cls();
  puts("Enter username:");
  gets(username);
  initMenu();
}

void select()
{
  switch (menuIndex) {
    case 0:
      viewTodos();
      break;
    case 1:
      addTodo();
      break;
    case 2:
      switchUser();
      break;
  }
}

void main()
{
  initMenu();

  while(1) {
    switch(joypad()) {
  		case J_UP : // If joypad() is equal to UP
  			moveUp();
  			delay(INPUT_DELAY);
  			break;
  		case J_DOWN : // If joypad() is equal to DOWN
  			moveDown();
  			delay(INPUT_DELAY);
  			break;
  		case J_START : // If joypad() is equal to START
  			select();
  			delay(INPUT_DELAY);
  			break;
  		case J_A : // If joypad() is equal to A
  			select();
  			delay(INPUT_DELAY);
  			break;
  		default :
  			break;
  	}
  }
}
