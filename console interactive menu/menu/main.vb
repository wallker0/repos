'main.vb
'credits to @wallker




Module main

    Public startopen = True



    'startup
    '========================================================================================
    Function preload()

        Console.SetWindowSize(90, 20)

        Console.BufferHeight = 20
        Console.BufferWidth = 90


        'reg menu check
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 65181872, Nothing) Is Nothing Then
            My.Computer.Registry.CurrentUser.CreateSubKey("menu")
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 65181872, "e64")
        End If


        'crpg and profilepic running status
        Dim p1 = Process.GetProcessesByName("crpg")
        Dim p2 = Process.GetProcessesByName("profilepic")
        If p1.Count > 0 Then
            c.selec1 = True
        End If
        If p2.Count > 0 Then
            c.selec2 = True
        End If


        'win10 aero functions
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 3475, Nothing) = 1 Then
            c.selec3 = True
        End If
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 3476, Nothing) = 1 Then
            c.selec4 = True
        End If


        'wakeup programs options
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


        'crpg and profpic starting with loop option
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 4785, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 4785, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 4785, Nothing) = 1 Then
            c.selec6 = True
        End If
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 4786, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 4786, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 4786, Nothing) = 1 Then
            c.selec7 = True
        End If
        If My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69860, Nothing) Is Nothing Then
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69860, 0)
        ElseIf My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", 69860, Nothing) = 1 Then
            c.selec8 = True
        End If


    End Function
    '========================================================================================

    Public c As New cvar()

    Public Declare Function Beep Lib "kernel32" (ByVal soundFrequency As Int32, ByVal soundDuration As Int32) As Int32


    'steam.exe location
    Public p1 = "D:\Steam\Steam.exe"

    'discord.exe location
    Public p2 = "C:\Users\wallker\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Discord Inc\Discord.lnk"

    'gclauncher.exe location
    Public p3 = "A:\GamersclubAC\GCLauncher.exe"

    'spotify.exe location
    Public p4 = "C:\Users\wallker\AppData\Roaming\Spotify\Spotify.exe"

    'razer synapse location
    Public p5 = "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Razer\Razer Synapse.lnk"

    'asus aura location
    Public p6 = "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\ASUS\AURA.lnk"

    'crpg.exe location
    Public p7 = "crpg.exe"

    'profilepic.exe
    Public p8 = "profilepic.exe"



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

                Console.ForegroundColor = red

                If i = 0 Then Console.WriteLine("  wallker’s menyoo")
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
