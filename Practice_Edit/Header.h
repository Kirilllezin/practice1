#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <time.h>

#define N '\n'
#define NN "\n\n"
using namespace std;

struct SystemData;
int ReadSizeOfSystem();
SystemData ReadTheSystem(int SizeOfSystem);
void PrintTheSystem(int SizeOfSystem, SystemData Row[]);
double FindDeterminant(int SizeOfSystem, SystemData Row[]);
double FindHelpersForDeterminant(int K, int SizeOfSystem, SystemData Row[]);
double FindXiKramer(int DetA, int DetH);
void Kramer(int SizeOfSystem);
SystemData FindReverseSystem(int SizeOfSystem, SystemData Row[], int i, int DetA);
void PrintTheReverseSystem(int SizeOfSystem, SystemData ReverseRow[]);
double FindXiReverse(int SizeOfSytem, SystemData ReverseRow[], SystemData Row[], int i);
void Reverse(int SizeOfSystem);


static int SizeOfSystem;
static char StartApp, StopApp;
static char Change;
