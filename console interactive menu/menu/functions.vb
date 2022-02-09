'functions.vb
'credits to @wallker




Module functions

    Function functions1()

        Dim optionsCount As Integer = 7
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


                If i = 0 Then Console.WriteLine("wakeup")
                If i = 1 Then Console.WriteLine(“killproc”)
                If i = 2 Then Console.WriteLine(“execute”)
                If i = 3 Then Console.WriteLine(“shutdown”)
                If i = 4 Then Console.WriteLine(“restart”)
                If i = 5 Then Console.WriteLine(“logoff”)
                If i = 6 Then Console.WriteLine("back")

                Console.ResetColor()
            Next

            Select Case Console.ReadKey(True).Key
                Case ConsoleKey.UpArrow
                    selected = Math.Max(0, selected - 1)
                Case ConsoleKey.DownArrow
                    selected = Math.Min(optionsCount - 1, selected + 1)
                Case ConsoleKey.Enter
                    If selected = 0 Then wakeup()
                    If selected = 1 Then prcsskill()
                    If selected = 2 Then execute1()
                    If selected = 3 Then shutdown("s")
                    If selected = 4 Then shutdown("r")
                    If selected = 5 Then shutdown("l")
                    If selected = 6 Then menu1()
            End Select

            If Not done Then Console.CursorTop = Console.CursorTop - optionsCount
        End While

    End Function

End Module
