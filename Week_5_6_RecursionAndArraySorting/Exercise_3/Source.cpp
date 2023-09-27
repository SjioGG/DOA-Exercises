#include <iostream>
#include <set>

void bookletPrint(int startPage, int endPage, int sheetNumber = 1)
{
    if (startPage > endPage)
    {
        return;
    }

    std::set<int> pageSet;

    // Add the pages to the set in the specified order
    pageSet.insert(startPage);
    pageSet.insert(endPage);

    if (startPage != endPage)
    {
        pageSet.insert(endPage - 1);
        pageSet.insert(startPage + 1);
    }

    // Print the sheet details
    std::cout << "Sheet " << sheetNumber << " contains pages ";
    for (int page : pageSet)
    {
        std::cout << page << ", ";
    }
    std::cout << std::endl;

    bookletPrint(startPage + 2, endPage - 2, sheetNumber++);
}

int main()
{
    // Example usage
    bookletPrint(1, 8);
    std::cout << std::endl;
    bookletPrint(1, 40);

    return 0;
}
