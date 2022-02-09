'main.vb
'credits to @wallker





Imports System.Globalization

Imports System.Object
Imports System.MarshalByRefObject
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.ComponentModel.Component
Imports System.Net.WebClient


Module main


    Public startopen = True


    'directories
    Public p1 = ""
    Public p2 = ""
    Public p3 = ""
    Public p4 = ""
    Public p5 = ""
    Public p6 = ""
    Public p7 = ""
    Public p8 = ""



    'startup
    '========================================================================================
    Function preload()

        updt()

        Console.SetWindowSize(105, 25)

        Console.BufferHeight = 25
        Console.BufferWidth = 105


        'validate key
        Dim f1 As String = "database\vers\key.dat"
        Dim v1 As String = File.ReadAllText(f1)
        Dim f2 As String = "database\vers\key2.dat"
        Dim v2 As String = File.ReadAllText(f2)
        If (v1 = v2) Then
            File.Delete(f2)
        Else
            write(“wrong or incompatible key detected..”, red, 30, 6)
            s(1000, 30, 7)
            File.Delete(f2)
            Environment.Exit(0)
        End If


        'wakeup options
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69852, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69852, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69852, Nothing) = 1 Then
            c.file1 = True
        End If
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69853, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69853, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69853, Nothing) = 1 Then
            c.file2 = True
        End If
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69854, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69854, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69854, Nothing) = 1 Then
            c.file3 = True
        End If
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69855, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69855, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69855, Nothing) = 1 Then
            c.file4 = True
        End If
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69856, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69856, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69856, Nothing) = 1 Then
            c.file5 = True
        End If
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69857, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69857, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69857, Nothing) = 1 Then
            c.file6 = True
        End If
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69858, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69858, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69858, Nothing) = 1 Then
            c.file7 = True
        End If
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69859, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69859, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69859, Nothing) = 1 Then
            c.file8 = True
        End If


    End Function
    '========================================================================================


    Public c As New cvar1()

    Public Declare Function Beep Lib "kernel32" (ByVal soundFrequency As Int32, ByVal soundDuration As Int32) As Int32


    Public white = ConsoleColor.White
    Public black = ConsoleColor.Black

    Public red = ConsoleColor.Red
    Public blue = ConsoleColor.Blue
    Public cyan = ConsoleColor.Cyan
    Public green = ConsoleColor.Green
    Public yellow = ConsoleColor.Yellow
    Public magenta = ConsoleColor.Magenta
    Public gray = ConsoleColor.Gray

    Public dred = ConsoleColor.DarkRed
    Public dblue = ConsoleColor.DarkBlue
    Public dcyan = ConsoleColor.DarkCyan
    Public dgreen = ConsoleColor.DarkGreen
    Public dyellow = ConsoleColor.DarkYellow
    Public dmagenta = ConsoleColor.DarkMagenta
    Public dgray = ConsoleColor.DarkGray


    Sub Main()

        preload()

        If startopen = True Then
            menu1()
        Else
            start1()
        End If

    End Sub


    'menu rendering
    '========================================================================================
    Function start1()
        Console.Clear()
        Dim optionsCount As Integer = 2
        Dim selected As Integer = 0
        Dim done As Boolean = False
        Dim exit1 = 0

        While Not done
            For i As Integer = 0 To optionsCount - 1

                Console.ForegroundColor = dgreen

                If i = 0 Then Console.WriteLine("welcome")
                If i = 1 Then Console.WriteLine()

                Console.ResetColor()
            Next

            Select Case Console.ReadKey(True).Key
                Case ConsoleKey.F12
                    menu1()
            End Select

            If Not done Then Console.CursorTop = Console.CursorTop - optionsCount
        End While

    End Function

    '========================================================================================

End Module
