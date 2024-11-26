#include <iostream>

using namespace std;

class String
{
private:
    int size;
    char* container;

public:
    String()
    {
        size = 0;
        container = nullptr;
    }

    void operator = (const char * word)
    {
        int arraySize = strlen(word) + 1;

        size = strlen(word);

        if (container == nullptr)
        {
            container = new char[arraySize];

            for (int i = 0; i < arraySize; i++)
            {
                container[i] = word[i];
            }
        }
        else
        {
            char* newContainer = new char[arraySize];

            for (int i = 0; i < arraySize; i++)
            {
                newContainer[i] = word[i];
            }

            delete container;

            container = newContainer;
        }


    }

    void Append(const char * word)
    {
        int newSize = strlen(container) + strlen(word);

        char* newContainer = new char[newSize];

        for (int i = 0; i < strlen(container); i++)
        {
            newContainer[i] = container[i];
        }
        for (int i = 0; i < strlen(word); i++)
        {
            newContainer[strlen(container)+ i] = word[i];
        }

        size = newSize;

        delete[] container;

        container = newContainer;

    }

    // int CompareString(const char* classString, const char* otherString)
    // {
    //     int size = 0;
    // 
    //     while (classString[size] != '\0' && otherString[size] != '\0') 
    //     {
    //         if (classString[size] != otherString[size]) 
    //         {
    //             return classString[size] - otherString[size]; 
    //         }
    //         size++; 
    //     }
    //     return classString[size] - otherString[size];
    // }

    int Compare(const char* word)
    {
        int count = 0;

        for (int i = 0; i < strlen(word); i++)
        {
            if (container[i] != word[i])
            {
                break;
            }
            else
            {
                count++;
            }
        }
        if (strlen(word) == count)
        {
            return 0;
        }

        int classString = 0;
        int otherString = 0;

        for (int i = 0; i < strlen(container); i++)
        {
            classString += container[i];
        }

        for (int i = 0; i < strlen(word); i++)
        {
            otherString += word[i];
        }

        if (classString > otherString)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    char operator [] (const int& index)
    {
        return container[index];
    }

    int& Size()
    {
        return size;
    }

    ~String()
    {
        if (container != nullptr)
        {
            delete[] container;
        }
    }

};

int main()
{
    String string;

    string = "Janna";

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];
    }

    cout << endl;

    string = "Bard";

    string.Append(" Character ");

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];
    }

    cout << endl;

    // const char* str1 = "apple";
    // const char* str2 = "banana";
    // 
    // cout << "\"" << str1 << "\" and \"" << str2 << "\": " << string.CompareString(str1, str2) << "\n";
    // cout << "\"" << str1 << "\" and \"" << str1 << "\": " << string.CompareString(str1, str1) << "\n";
    // cout << "\"" << str2 << "\" and \"" << str1 << "\": " << string.CompareString(str2, str1) << "\n";



    return 0;
}