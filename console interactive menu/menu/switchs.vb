'switchs.vb
'credits to @itzwallker




Module switchs

    Function switchs1()

        preload()

        Dim optionsCount As Integer = 6
        Dim selected As Integer = 0
        Dim done As Boolean = False
        Console.CursorTop = 6

        While Not done
            For i As Integer = 0 To optionsCount - 1

                Console.CursorLeft = 15

                If selected = i Then
                    Console.ForegroundColor = red
                    Console.Write(". ")
                Else
                    Console.ForegroundColor = gray
                    Console.Write("  ")
                End If

                If i = 0 Then
                    If c.selec1 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine("crpg")
                End If
                If i = 1 Then
                    If c.selec2 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine(“profpic”)
                End If
                If i = 2 Then
                    If c.selec3 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine(“win10-border”)
                End If
                If i = 3 Then
                    If c.selec4 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine(“win10-color”)
                End If
                If i = 4 Then
                    If c.selec5 Then
                        Console.ForegroundColor = red
                        Console.Write("[1] ")
                    Else
                        Console.ForegroundColor = gray
                        Console.Write("[0] ")
                    End If
                    Console.WriteLine(“test4”)
                End If
                If i = 5 Then
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
                    If selected = 5 Then
                        menu1()
                    End If

                Case ConsoleKey.RightArrow ' activate the function
                    If selected = 0 Then
                        If c.selec1 = False Then
                            Process.Start(p7)
                            Beep(600, 2)
                            c.selec1 = True
                        End If
                    End If
                    If selected = 1 Then
                        If c.selec2 = False Then
                            Process.Start(p8)
                            Beep(600, 2)
                            c.selec2 = True
                        End If
                    End If
                    If selected = 2 Then
                        If c.selec3 = False Then
                            Try
                                My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Control Panel\Desktop\WindowMetrics", "BorderWidth", "0")
                                My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Control Panel\Desktop\WindowMetrics", "PaddedBorderWidth", "0")
                                Beep(600, 2)
                                My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 3475, 1)
                                c.selec3 = True
                            Catch ex As Exception
                                write(ex, white, 30, 6)
                            End Try
                        End If
                    End If
                    If selected = 3 Then
                        If c.selec4 = False Then

                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\DWM", "EnableWindowColorization", 1, Microsoft.Win32.RegistryValueKind.DWord)
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\DWM", "AccentColorInactive", 1, Microsoft.Win32.RegistryValueKind.DWord)
                            Beep(600, 2)
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 3476, 1)
                            c.selec4 = True
                        End If
                    End If
                    If selected = 4 Then
                        If c.selec5 = False Then
                            Beep(600, 2)
                            c.selec5 = True
                        End If
                    End If

                Case ConsoleKey.LeftArrow 'deactivate the function
                    If selected = 0 Then
                        If c.selec1 = True Then
                            procK(“crpg”)
                            Beep(400, 2)
                            c.selec1 = False
                        End If
                    End If
                    If selected = 1 Then
                        If c.selec2 = True Then
                            procK(“profilepic”)
                            Beep(400, 2)
                            c.selec2 = False
                        End If
                    End If
                    If selected = 2 Then
                        If c.selec3 = True Then
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Control Panel\Desktop\WindowMetrics", "BorderWidth", "-15")
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Control Panel\Desktop\WindowMetrics", "PaddedBorderWidth", "-60")
                            Beep(400, 2)
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 3475, 0)
                            c.selec3 = False
                        End If
                    End If
                    If selected = 3 Then
                        If c.selec4 = True Then
                            'My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\DWM", "EnableWindowColorization", 0, Microsoft.Win32.RegistryValueKind.DWord)
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\DWM", "AccentColorInactive", 16777215, Microsoft.Win32.RegistryValueKind.DWord)
                            Beep(400, 2)
                            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", 3476, 0)
                            c.selec4 = False
                        End If
                    End If
                    If selected = 4 Then
                        If c.selec5 = True Then
                            Beep(400, 2)
                            c.selec5 = False
                        End If
                    End If

            End Select

            If Not done Then Console.CursorTop = Console.CursorTop - optionsCount
        End While

    End Function

End Module
