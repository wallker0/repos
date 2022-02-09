'menu.vb
'credits to @wallker





Imports System.Globalization

Imports System.Object
Imports System.MarshalByRefObject
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.ComponentModel.Component
Imports System.Net.WebClient


Module menu

    Function menu1()

        Console.Clear()

        Dim optionsCount As Integer = 7
        Dim selected As Integer = 0
        Dim done As Boolean = False
        Dim exit1 = 0

        While Not done
            For i As Integer = 0 To optionsCount - 1

                Console.CursorLeft = 3

                If selected = i Then
                    Console.ForegroundColor = dgreen
                    Console.Write("  ")
                    'Console.ForegroundColor = red
                Else
                    Console.ForegroundColor = gray
                    Console.Write("  ")
                End If

                If i = 0 Then
                    Console.CursorLeft -= 3
                    Console.ForegroundColor = dgreen
                    Dim f1 As String = "database\vers\key.dat"
                    Dim v1 As String = File.ReadAllText(f1)
                    Dim r As String = CInt(Math.Ceiling(Rnd() * 999999999)) + 1
                    Console.Title = r
                    Console.WriteLine(" [ " + r + " ]")
                    write(DateTime.Now.ToString("dd/MM/yyyy HH:mm:ss") + "  " + dolar, white, 80, 1)
                    Console.ForegroundColor = white
                    Console.CursorLeft += 3
                End If
                If i = 1 Then Console.WriteLine("")
                If i = 2 Then Console.WriteLine("empresas")
                If i = 3 Then Console.WriteLine("registrar")
                If i = 4 Then Console.WriteLine("editar")
                If i = 5 Then Console.WriteLine("bank")
                If i = 6 Then Console.WriteLine("exit")

                Console.ResetColor()
            Next

            Select Case Console.ReadKey(True).Key
                Case ConsoleKey.UpArrow
                    selected = Math.Max(0, selected - 1)
                Case ConsoleKey.DownArrow
                    selected = Math.Min(optionsCount - 1, selected + 1)
                Case ConsoleKey.F12
                    start1()
                Case ConsoleKey.Enter
                    If selected = 0 Then menu1()

                    If selected = 2 Then empresas1()
                    If selected = 3 Then registrar1()
                    If selected = 4 Then editar1()
                    If selected = 5 Then menu1()
                    If selected = 6 Then Environment.Exit(0)

                Case ConsoleKey.F1
                    regemp1()
                Case ConsoleKey.F2
                    regpag1()
                Case ConsoleKey.F3
                    reganot1()

            End Select

            If Not done Then Console.CursorTop = Console.CursorTop - optionsCount
        End While

    End Function

End Module
