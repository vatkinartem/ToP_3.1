#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include "MyFigureLib.h"
#include "myExceptions.h"
#include <malloc.h>
#include <string.h>

namespace myNS {
    enum COMMANDS {
        help = 0,
        load = 1,
        save = 2,
        square = 3,
        exit = 4
    };

    enum TYPEOFFIGURES {
        defaultFig = 0,
        circle = 1,
        rectangle = 2,
        recttriangle = 3,
        trapezoid = 4,
    };
}

using namespace myNS;

void loadData(Circle& circle, Rectangle& rectangle, RectTriangle& rectTriangle, Trapezoid& trapezoid);

void saveData(Circle& circle, Rectangle& rectangle, RectTriangle& rectTriangle, Trapezoid& trapezoid);

int main()
{
    Circle circle;
    Rectangle rectangle;
    RectTriangle rectTriangle;
    Trapezoid trapezoid;
    
    loadData(circle, rectangle, rectTriangle, trapezoid);

    /*array of Figure pointers to show how virtual functions and abstract classes work*/
    Figure** arrFig = new Figure * [4]; 
    arrFig[0] = &circle;
    arrFig[1] = &rectangle;
    arrFig[2] = &rectTriangle;
    arrFig[3] = &trapezoid;
    printf("\nFigure** arrFig (getAray() is virtual function):\n");
    for (int i = 0; i < 4; i++)
    {
        printf("arrFig[%d].getArea() = %.3f\n", i, arrFig[i]->getArea());
    }
    delete[] arrFig;
    /*end of that block of code*/

    COMMANDS com;

    printf("\n%d - help\n", COMMANDS::help);

    do
    {
        printf("\nInput command...\n");
        try
        {
            if (scanf("%d", &com) == 0)
            {
                throw NonNumericInputException("Exception. Non Numeric input found.");
            };
        }
        catch (const NonNumericInputException& MetNonNumericExeption)
        {
            char c;
            do
            {
                c = getc(stdin);
            }while ((c != EOF) and (c != '\n') and (c != ' '));
            printf("%s\n", MetNonNumericExeption.what());
        }
        catch (...) {
            printf("Undefined exeption cought\n");
            break;
        }

        switch (com)
        {
        case COMMANDS::square:
            printf("circle square = %.3f,\nrectangle square = %.3f,\nrectTriangle square = %.3f,\ntrapezoid square = %.3f\n",\
            circle.getArea(), rectangle.getArea(), rectTriangle.getArea(), trapezoid.getArea());
            break;
        case COMMANDS::load:
            loadData(circle, rectangle, rectTriangle, trapezoid);
            break;
        case COMMANDS::save:
            saveData(circle, rectangle, rectTriangle, trapezoid);
            break;
        case COMMANDS::help:
            printf("%d - square\n%d - help\n%d - exit program\n%d - load\n%d - save\n",\
                COMMANDS::square, COMMANDS::help, COMMANDS::exit, COMMANDS::load, COMMANDS::save);
            break;
        case COMMANDS::exit:
            break;
        default:
            printf("Invalid command.\n");
            break;
        }
    } while (com != COMMANDS::exit);

    return 1337;
}

void loadData(Circle& circle, Rectangle& rectangle, RectTriangle& rectTriangle, Trapezoid& trapezoid) {
    printf("Starting loading data from file\n");
    FILE* inputFile = NULL;
    float tempVar0 = 0, tempVar1 = 0, tempVar2 = 0;
    TYPEOFFIGURES figType = TYPEOFFIGURES::defaultFig;
    int scanRes = 0;

    inputFile = fopen("input.txt", "rt");
    if (inputFile == NULL)
    {
        printf("Failed to open load file\n");
        return;
    }

    char* line = new char[128];
    memset(line, 0, 128);

    do
    {
        tempVar0 = 0; tempVar1 = 0; tempVar2 = 0;
        figType = TYPEOFFIGURES::defaultFig;

        try
        {
            line = fgets(line, 1024, inputFile);
            if (line == nullptr)
            {
                break;
            }

            scanRes = sscanf(line, "%d", &figType);
            if ((figType == TYPEOFFIGURES::defaultFig) or (scanRes == 0))
            {
                throw figureTypeException("Wrong figure type.");
            }
            scanRes = sscanf(line, "%*d %f %f %f", &tempVar0, &tempVar1, &tempVar2);
            if (scanRes == 0)
            {
                throw figureParameterException("Wrong format of figure parameter.");
            }
            if ((tempVar0 < 0) or (tempVar1 < 0) or (tempVar2 < 0))
            {
                throw figureParameterException("Wrong value of figure parameter. One of parameters is lower then 0.");
            }
        }
        catch (const figureTypeException& wrongFigureType)
        {
            printf("%s\n", wrongFigureType.what());
            continue;
        }
        catch (const figureParameterException& wrongFigureParameter) {
            printf("%s\n", wrongFigureParameter.what());
            continue;
        }
        catch (...) {
            printf("Unknown exeption found.\n");
            continue;
        }

        switch (figType)
        {
        case TYPEOFFIGURES::circle:       
            circle = { tempVar0 };
            break;
        case TYPEOFFIGURES::rectangle:

            rectangle = { tempVar0 , tempVar1 };
            break;
        case TYPEOFFIGURES::recttriangle:

            rectTriangle = { tempVar0 , tempVar1 };
            break;
        case TYPEOFFIGURES::trapezoid:

            trapezoid = { tempVar0 , tempVar1 , tempVar2 };
            break;
        default:
            printf("Wrong type load\n");
            break;
        }
    } while ((!feof(inputFile)));

    delete[] line;
    fclose(inputFile);
    printf("Finished loading data from file\n");
}

void saveData(Circle& circle, Rectangle& rectangle, RectTriangle& rectTriangle, Trapezoid& trapezoid) {
    printf("Starting saving data to file\n");
    FILE* outputFile = NULL;
    outputFile = fopen("output.txt", "wt");
    if (outputFile == NULL)
    {
        printf("Failed to open save file\n");
        return;
    }

    fprintf(outputFile, "circle square = %.3f\nrectangle square = %.3f\nrectTriangle square = %.3f\ntrapezoid square = %.3f\n", \
        circle.getArea(), rectangle.getArea(), rectTriangle.getArea(), trapezoid.getArea());

    fclose(outputFile);
    printf("Finished loading data to file\n");
}