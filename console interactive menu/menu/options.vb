'options.vb
'credits to @wallker




Module options

    Function options1()

        Dim optionsCount As Integer = 12
        Dim selected As Integer = 0
        Dim done As Boolean = False
        Console.CursorTop = 6

        While Not done
            For i As Integer = 0 To optionsCount - 1

                Console.CursorLeft = 16

                If selected = i Then
                    Console.ForegroundColor = red
                    Console.Write(". ")
                Else
                    Console.ForegroundColor = gray
                    Console.Write("  ")
                End If

                If i = 0 Then
                    If c.selec6 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("crpg startup loop")
                End If
                If i = 1 Then
                    If c.selec7 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("profpic startup loop")
                End If
                If i = 2 Then
                    If c.file1 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("open steam on startup")
                End If
                If i = 3 Then
                    If c.file2 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("open discord on startup")
                End If
                If i = 4 Then
                    If c.file3 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("open gclauncher on startup")
                End If
                If i = 5 Then
                    If c.file4 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("open spotify on startup")
                End If
                If i = 6 Then
                    If c.file5 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("open synapse on startup")
                End If
                If i = 7 Then
                    If c.file6 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("open aura on startup")
                End If
                If i = 8 Then
                    If c.file7 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("open crpg on startup")
                End If
                If i = 9 Then
                    If c.file8 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("open profilepic on startup")
                End If
                If i = 10 Then
                    If c.selec8 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("profilepic notifications")
                End If
                If i = 11 Then
                    Console.ForegroundColor = gray
                    Console.WriteLine("    back")
                End If

                Console.ResetColor()
            Next

            Select Case Console.ReadKey(True).Key
                Case ConsoleKey.UpArrow
                    selected = Math.Max(0, selected - 1)

                Case ConsoleKey.DownArrow
                    selected = Math.Min(optionsCount - 1, selected + 1)

                Case ConsoleKey.Enter
                    If selected = 11 Then
                        menu1()
                    End If

                Case ConsoleKey.RightArrow ' activ the function
                    If selected = 0 Then
                        If c.selec6 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 4785, 1)
                            Beep(600, 2)
                            c.selec6 = True
                        End If
                    End If
                    If selected = 1 Then
                        If c.selec7 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 4786, 1)
                            Beep(600, 2)
                            c.selec7 = True
                        End If
                    End If
                    If selected = 2 Then
                        If c.file1 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69852, 1)
                            Beep(600, 2)
                            c.file1 = True
                        End If
                    End If
                    If selected = 3 Then
                        If c.file2 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69853, 1)
                            Beep(600, 2)
                            c.file2 = True
                        End If
                    End If
                    If selected = 4 Then
                        If c.file3 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69854, 1)
                            Beep(600, 2)
                            c.file3 = True
                        End If
                    End If
                    If selected = 5 Then
                        If c.file4 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69855, 1)
                            Beep(600, 2)
                            c.file4 = True
                        End If
                    End If
                    If selected = 6 Then
                        If c.file5 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69856, 1)
                            Beep(600, 2)
                            c.file5 = True
                        End If
                    End If
                    If selected = 7 Then
                        If c.file6 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69857, 1)
                            Beep(600, 2)
                            c.file6 = True
                        End If
                    End If
                    If selected = 8 Then
                        If c.file7 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69858, 1)
                            Beep(600, 2)
                            c.file7 = True
                        End If
                    End If
                    If selected = 9 Then
                        If c.file8 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69859, 1)
                            Beep(600, 2)
                            c.file8 = True
                        End If
                    End If
                    If selected = 10 Then
                        If c.selec8 = False Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69860, 1)
                            Beep(600, 2)
                            c.selec8 = True
                        End If
                    End If

                Case ConsoleKey.LeftArrow 'deactiv the function
                    If selected = 0 Then
                        If c.selec6 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 4785, 0)
                            Beep(400, 2)
                            c.selec6 = False
                        End If
                    End If
                    If selected = 1 Then
                        If c.selec7 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 4786, 0)
                            Beep(400, 2)
                            c.selec7 = False
                        End If
                    End If
                    If selected = 2 Then
                        If c.file1 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69852, 0)
                            Beep(400, 2)
                            c.file1 = False
                        End If
                    End If
                    If selected = 3 Then
                        If c.file2 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69853, 0)
                            Beep(400, 2)
                            c.file2 = False
                        End If
                    End If
                    If selected = 4 Then
                        If c.file3 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69854, 0)
                            Beep(400, 2)
                            c.file3 = False
                        End If
                    End If
                    If selected = 5 Then
                        If c.file4 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69855, 0)
                            Beep(400, 2)
                            c.file4 = False
                        End If
                    End If
                    If selected = 6 Then
                        If c.file5 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69856, 0)
                            Beep(400, 2)
                            c.file5 = False
                        End If
                    End If
                    If selected = 7 Then
                        If c.file6 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69857, 0)
                            Beep(400, 2)
                            c.file6 = False
                        End If
                    End If
                    If selected = 8 Then
                        If c.file7 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69858, 0)
                            Beep(400, 2)
                            c.file7 = False
                        End If
                    End If
                    If selected = 9 Then
                        If c.file8 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69859, 0)
                            Beep(400, 2)
                            c.file8 = False
                        End If
                    End If
                    If selected = 10 Then
                        If c.selec8 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 69860, 0)
                            Beep(400, 2)
                            c.selec8 = False
                        End If
                    End If

            End Select

            If Not done Then Console.CursorTop = Console.CursorTop - optionsCount
        End While

    End Function

End Module
