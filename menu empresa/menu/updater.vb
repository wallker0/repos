'updater.vb
'credits to @wallker





Imports System.Globalization

Imports System.Object
Imports System.MarshalByRefObject
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.ComponentModel.Component
Imports System.Net.WebClient


Module updater


    Function updt()

        'used to check/update version
        Dim kek As String = "database\vers\vers.dat"

        Dim myWebClient As New Net.WebClient()

        Dim remoteUri1 As String = "https://wallkerii.000webhostapp.com/sind/vers.dat"
        Dim fileName1 As String = "vers.dat"

        'Dim remoteUri2 As String = decCH("https://wallkerii.000webhostapp.com/sind/sind.exel", -4)
        'Dim fileName2 As String = decCH("sind.exel", -4)

        Dim remoteUri3 As String = "https://wallkerii.000webhostapp.com/sind/settings.xml"
        Dim fileName3 As String = "settings.xml"

        Dim remoteUri4 As String = "https://wallkerii.000webhostapp.com/sind/key.dat"
        Dim fileName4 As String = "key.dat"


        Dim myStringWebResource1 As String = Nothing
        'Dim myStringWebResource2 As String = Nothing
        Dim myStringWebResource3 As String = Nothing
        Dim myStringWebResource4 As String = Nothing

        myStringWebResource1 = remoteUri1
        'myStringWebResource2 = remoteUri2
        myStringWebResource3 = remoteUri3
        myStringWebResource4 = remoteUri4


        Console.WriteLine("checking files..")
        System.Threading.Thread.Sleep(800)

        If FileExists(kek) = False Then

            System.IO.Directory.CreateDirectory("database\vers\")
            System.IO.Directory.CreateDirectory("database\empr\")
            System.IO.Directory.CreateDirectory("database\empr\pagas")
            System.IO.Directory.CreateDirectory("database\empr\naopagas")
            System.IO.Directory.CreateDirectory("database\empr\emaberto")
            System.IO.Directory.CreateDirectory("database\pagtos\")
            System.IO.Directory.CreateDirectory("database\anot\")

            Console.WriteLine("downloading files..")
            System.Threading.Thread.Sleep(1000)

            myWebClient.DownloadFile(myStringWebResource4, "database\vers\" + "key.dat")

            myWebClient.DownloadFile(myStringWebResource1, "database\vers\" + fileName1)
            'myWebClient.DownloadFile(myStringWebResource2, decCH("\vers\", -4) + fileName2)
            myWebClient.DownloadFile(myStringWebResource3, "database\vers\" + fileName3)
            'myWebClient.DownloadFile(myStringWebResource4, decCH("\vers\", -4) + fileName4)

            'My.Computer.FileSystem.RenameFile(decCH("\vers\key.dat", -4), decCH("ei.exe", -4))

        ElseIf FileExists(kek) = True Then

            Console.WriteLine("file already exists.. updating?..")
            System.Threading.Thread.Sleep(700)
            Dim value1 As String = File.ReadAllText(kek)
            myWebClient.DownloadFile(myStringWebResource1, "database\vers\" + "vers2.dat")
            Dim kek2 As String = "database\vers\vers2.dat"
            Dim value2 As String = File.ReadAllText(kek2)

            If (value1 = value2) = False Then

                File.Delete(kek)
                File.Delete(kek2)

                Console.WriteLine("downloading files..")
                System.Threading.Thread.Sleep(500)
                myWebClient.DownloadFile(myStringWebResource1, "database\vers\" + fileName1)
                'myWebClient.DownloadFile(myStringWebResource2, decCH("\vers\", -4) + fileName2)
                myWebClient.DownloadFile(myStringWebResource3, "database\vers\" + fileName3)
                'myWebClient.DownloadFile(myStringWebResource4, decCH("\vers\", -4) + fileName4)

            Else

                File.Delete(kek2)

                Console.WriteLine("files already updated.. starting up..")

            End If

        End If

        Console.WriteLine("loading..")
        System.Threading.Thread.Sleep(500)

        myWebClient.DownloadFile(myStringWebResource4, "database\vers\" + "key2.dat")

        Console.WriteLine("sucess!")
        System.Threading.Thread.Sleep(300)

    End Function

End Module
