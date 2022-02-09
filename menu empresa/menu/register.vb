'register.vb
'credits to @wallker





Imports System.Globalization

Imports System.Object
Imports System.MarshalByRefObject
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.ComponentModel.Component
Imports System.Net.WebClient


Module register

    Function registrar1()


        Dim optionsCount As Integer = 4
        Dim selected As Integer = 0
        Dim done As Boolean = False
        Dim exit1 = 0
        Console.CursorTop = 6

        While Not done
            For i As Integer = 0 To optionsCount - 1

                Console.CursorLeft = 15

                If selected = i Then
                    Console.ForegroundColor = dgreen
                    Console.Write(". ")
                    'Console.ForegroundColor = red
                Else
                    Console.ForegroundColor = gray
                    Console.Write("  ")
                End If


                If i = 0 Then Console.WriteLine("registrar empresa")
                If i = 1 Then Console.WriteLine(“registrar pagamento”)
                If i = 2 Then Console.WriteLine(“registrar anotacao”)
                If i = 3 Then Console.WriteLine("back")

                Console.ResetColor()
            Next

            Select Case Console.ReadKey(True).Key
                Case ConsoleKey.UpArrow
                    selected = Math.Max(0, selected - 1)
                Case ConsoleKey.DownArrow
                    selected = Math.Min(optionsCount - 1, selected + 1)
                Case ConsoleKey.Enter
                    If selected = 0 Then regemp1()
                    If selected = 1 Then regpag1()
                    If selected = 2 Then reganot1()
                    If selected = 3 Then menu1()
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
