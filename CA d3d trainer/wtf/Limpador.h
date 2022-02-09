#include <windows.h>
#include <stdio.h>

bool fSuccess;

int LimparLogs(int argc, char *argv[])
{
   BOOL fSuccess = true;
   
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\BlackCipher\\BlackCall.log"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\BlackCipher\\BlackCipher.log"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\BlackCipher\\BlackXchg.log"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\BlackCipher\\NGClient.log"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\HShield\\ahnrpt.exe"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\HShield\\ahnrpt.ini"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\HShield\\hshield.log"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\HShield\\HSUpChk.log"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\HShield\\supdate.log"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\HShield\\hsupdate.jpg"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\HShield\\splash.jpg"));
   fSuccess = DeleteFile(TEXT("C:\\Level Up! Games\\Combat Arms\\HShield\\Update\\supdate.log"));
;

   if (!fSuccess)
   {
      printf ("DeleteFile() failed, error %d\n", GetLastError());
      return (6);
   }
     else
         printf ("DeleteFile() is  OK!\n");
   
   return (0);

   
}