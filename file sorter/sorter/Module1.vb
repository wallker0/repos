Imports System
Imports System.Object
Imports System.MarshalByRefObject
Imports System.Globalization
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.String

Module Module1

    Public Declare Function Beep Lib "kernel32" (ByVal soundFrequency As Int32, ByVal soundDuration As Int32) As Int32

    Public fdir = "C:\"

    Function FileExists(FilePath As String) As Boolean
        Dim TestStr As String
        TestStr = ""
        On Error Resume Next
        TestStr = Dir(FilePath)
        On Error GoTo 0
        If TestStr = "" Then
            FileExists = False
        Else
            FileExists = True
        End If
    End Function

    Function GetN(ByVal folderPath As String) As String
        Dim files() As String = Directory.GetFiles(folderPath, "*.*")
        Dim random As Random = New Random()
        Return files(random.Next(0, files.Length - 1))
    End Function

    Dim lp = 0

    Public Sub tick(ByVal sender As Object, ByVal e As System.Timers.ElapsedEventArgs)
        Console.Write(" tick")
    End Sub

    Sub Main()
        'If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", "4786", Nothing) = 1 Then loop1()
        main1()
    End Sub

    Function main1()
        Console.Clear()

        Dim optionsCount As Integer = 5
        Dim selected As Integer = 0
        Dim done As Boolean = False
        Dim exit1 = 0

        While Not done
            For i As Integer = 0 To optionsCount - 1

                If selected = i Then
                    Console.ForegroundColor = ConsoleColor.Red
                    Console.Write("> ")
                Else
                    Console.Write("  ")
                End If

                If i = 0 Then Console.WriteLine("loop")
                If i = 1 Then Console.WriteLine("hash")
                If i = 2 Then Console.WriteLine("rename")
                If i = 3 Then Console.WriteLine("random")
                If i = 4 Then Console.WriteLine("exit")

                Console.ResetColor()
            Next

            Select Case Console.ReadKey(True).Key
                Case ConsoleKey.UpArrow
                    selected = Math.Max(0, selected - 1)
                Case ConsoleKey.DownArrow
                    selected = Math.Min(optionsCount - 1, selected + 1)
                Case ConsoleKey.Enter
                    done = True
            End Select

            If Not done Then Console.CursorTop = Console.CursorTop - optionsCount
        End While

        Do
            If selected = 0 Then loop1()
            If selected = 1 Then hash()
            If selected = 2 Then rename()
            If selected = 3 Then random()
            If selected = 4 Then exit1 = 1
        Loop Until exit1 = 1

    End Function

    Function loop1()
        Dim aTimer As New System.Timers.Timer
        aTimer.AutoReset = True
        aTimer.Interval = 100000 '2 seconds
        AddHandler aTimer.Elapsed, AddressOf tick
        aTimer.Start()

        Do
            Console.ForegroundColor = ConsoleColor.White
            Console.BackgroundColor = ConsoleColor.Black

            Console.Clear()

            Console.ForegroundColor = ConsoleColor.White
            Console.BackgroundColor = ConsoleColor.Blue

            Console.WriteLine()
            Console.WriteLine($"file: [ {GetN(fdir)} ]")
            Console.WriteLine()


            If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69860, Nothing) = 1 Then
                MsgBox("new one!")
            Else
                Beep(600, 2)
            End If

            'System.Threading.Thread.Sleep(1000)
            System.Threading.Thread.Sleep(2700000)

            If Console.KeyAvailable Then
                If Console.ReadKey(True).KeyChar = "q"c Then lp = 1
            End If
        Loop Until lp = 1
        Main()
    End Function

End Module
