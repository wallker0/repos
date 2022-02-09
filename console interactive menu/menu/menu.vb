'menu.vb
'credits to @wallker




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
                    Console.ForegroundColor = red
                    Console.Write("> ")
                    'Console.ForegroundColor = red
                Else
                    Console.ForegroundColor = gray
                    Console.Write("  ")
                End If

                If i = 0 Then
                    Console.CursorLeft -= 3
                    Console.ForegroundColor = red
                    Console.WriteLine("wallker’s menyoo")
                    Console.ForegroundColor = white
                    Console.CursorLeft += 3
                End If
                If i = 1 Then Console.WriteLine("")
                If i = 2 Then Console.WriteLine("functions")
                If i = 3 Then Console.WriteLine("switchs")
                If i = 4 Then Console.WriteLine("regedit")
                If i = 5 Then Console.WriteLine("config")
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
                    If selected = 1 Then menu1()
                    If selected = 2 Then functions1()
                    If selected = 3 Then switchs1()
                    If selected = 4 Then regedit1()
                    If selected = 5 Then options1()
                    If selected = 6 Then Environment.Exit(0)
            End Select

            If Not done Then Console.CursorTop = Console.CursorTop - optionsCount
        End While

    End Function

End Module
