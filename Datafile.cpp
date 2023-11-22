#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
   ifstream ifile;
   string inform, fname;
   char ch;
   cout << "Enter file name: ";
   getline(cin, fname);
   ifile.open(fname);
   if (ifile)
   {
      cout << "The entered file already exists. Please try again.\n";
      return 0;
   }
   else
   {
      ifile.close();
      ofstream fout(fname);
      if (!fout)
      {
         cout << "Error creating the file!\n";
         return 0;
      }
      cout << "Enter a line to store in the file: ";
      getline(cin, inform);
      fout << inform << "\n";
      cout << "\nThe information you entered was successfully saved!\n";
      fout.close();
      cout << "\nDo you want to read the file \"" << fname << "\"? (y/n): ";
      cin >> ch;
      if (ch == 'y' || ch == 'Y')
      {
         string myline;
         ifstream ifile(fname);
         while (getline(ifile, myline))
         {
            cout << myline;
         }
         ifile.close();
      }
   }
   cout << endl;
   return 0;
}
