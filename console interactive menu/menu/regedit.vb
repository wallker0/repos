'regedit.vb
'credits to @wallker




Module regedit

    Function regedit1()

        Dim optionsCount As Integer = 4
        Dim selected As Integer = 0
        Dim done As Boolean = False
        Dim exit1 = 0
        Console.CursorTop = 6

        While Not done
            For i As Integer = 0 To optionsCount - 1

                Console.CursorLeft = 15

                If selected = i Then
                    Console.ForegroundColor = red
                    Console.Write(". ")
                    'Console.ForegroundColor = red
                Else
                    Console.ForegroundColor = gray
                    Console.Write("  ")
                End If


                If i = 0 Then Console.WriteLine("read")
                If i = 1 Then Console.WriteLine("add new")
                If i = 2 Then Console.WriteLine(“delete”)
                If i = 3 Then Console.WriteLine("back")

                Console.ResetColor()
            Next

            Select Case Console.ReadKey(True).Key
                Case ConsoleKey.UpArrow
                    selected = Math.Max(0, selected - 1)
                Case ConsoleKey.DownArrow
                    selected = Math.Min(optionsCount - 1, selected + 1)
                Case ConsoleKey.Enter
                    If selected = 0 Then read1()
                    If selected = 1 Then add1()
                    If selected = 2 Then rem1()
                    If selected = 3 Then menu1()
            End Select

            If Not done Then Console.CursorTop = Console.CursorTop - optionsCount
        End While

    End Function

End Module
