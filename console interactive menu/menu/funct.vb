'funct.vb
'credits to @wallker




Module funct

    'sleep
    Function s(t As Integer, x As Integer, y As Integer)
        Try
            Console.SetCursorPosition(x, y)
            System.Threading.Thread.Sleep(t / 3)
            Console.Write(“.”)
            System.Threading.Thread.Sleep(t / 3)
            Console.Write(“.”)
            System.Threading.Thread.Sleep(t / 3)
            Console.Write(“.”)
        Catch ex As Exception
            Console.Write(ex)
            Console.ReadLine()
        End Try
    End Function


    'console write
    Function write(s, color, x, y)
        Try
            Console.ForegroundColor = color
            Console.SetCursorPosition(x, y)
            Console.Write(s)
            Console.ResetColor()

        Catch ex As Exception
            Console.ForegroundColor = ConsoleColor.Magenta
            Console.SetCursorPosition(24, 36)
            Console.Write(ex)
            Console.ResetColor()
            Console.ReadLine()

        End Try
    End Function


    'process kill
    Function procK(process)
        Dim prc() As Process = System.Diagnostics.Process.GetProcessesByName(process)
        Try
            For Each p As Process In prc
                p.Kill()
            Next
        Catch ex As Exception
            Console.WriteLine(ex)
            Console.ReadLine()
        End Try
    End Function


    'usage: shutdown("-s" / "-r" / "-l")
    Function shutdown(s As String)
        If s = "s" Then
            Process.Start("shutdown", "-s -t 00")
        ElseIf s = "r" Then
            Process.Start("shutdown", "-r -t 00")
        ElseIf s = "l" Then
            Process.Start("shutdown", "-l -t 00")
        End If
    End Function


    'file check
    Function FileExists(fp As String) As Boolean
        Dim t As String
        t = ""
        On Error Resume Next
        t = Dir(fp)
        On Error GoTo 0
        If t = "" Then
            FileExists = False
        Else
            FileExists = True
        End If
    End Function


    'decrypter
    Function dec(s As String, v As Integer) As String
        Dim o As String = String.Empty
        Dim c As Char
        For i = 0 To Len(s) - 1
            c = s.Substring(i, 1)
            o += Chr(Asc(c) + v)
        Next

        Return o
    End Function


    'encrypter
    Function enc(s As String, v As Integer) As String
        Dim o As String = String.Empty
        Dim c As Char
        For i = 0 To Len(s) - 1
            c = s.Substring(i, 1)
            o += Chr(Asc(c) - v)
        Next

        Return o
    End Function


    'framerate counter,
    Public currentFrameRate As Integer

    'to call it use 
    'Call avanceFrameRate()
    'and write it..
    'write(currentFrameRate, green, 44, 0)

    Public Sub advanceFrameRate()
        Static ptlu As Double 'time of last framerate update
        Static callCount As Integer
        'increment the callCounter
        callCount += 1
        'change 1000 to any desired time value

        If (Environment.TickCount - ptlu) >= 1000 Then
            currentFrameRate = callCount
            'reset the callCount after updating the value
            callCount = 0
            'reset the time updated
            ptlu = Environment.TickCount

        Else
        End If

    End Sub


    'wake up function
    Function wakeup()
        If c.file1 = True Then
            Process.Start(p1)
        End If
        If c.file2 = True Then
            Process.Start(p2)
        End If
        If c.file3 = True Then
            Process.Start(p3)
        End If
        If c.file4 = True Then
            Process.Start(p4)
        End If
        If c.file5 = True Then
            Process.Start(p5)
        End If
        If c.file6 = True Then
            Process.Start(p6)
        End If
        If c.file7 = True Then
            Process.Start(p7)
        End If
        If c.file8 = True Then
            Process.Start(p8)
        End If

        s(600, 30, 3)
        write(“done..”, white, 30, 2)
        menu1()

    End Function


    'process kill function
    Function prcsskill()
        write(“process name:”, white, 35, 2)
        Dim resp = Console.ReadLine()
        s(300, 35, 4)

        Try
            procK(resp)
        Catch ex As Exception
            Console.Write(ex)
            Console.ReadLine()
            functions1()
        End Try

        write(“done..”, white, 35, 3)
        s(300, 34, 4)
        menu1()

    End Function


    'process execute function
    Function execute1()
        write(“process name:”, white, 35, 2)
        Dim resp = Console.ReadLine()
        s(300, 35, 4)

        Try
            If resp = "steam" Then
                Process.Start(p1)
            ElseIf resp = "discord" Then
                Process.Start(p2)
            ElseIf resp = "gclauncher" Then
                Process.Start(p3)
            ElseIf resp = "spotify" Then
                Process.Start(p4)
            ElseIf resp = "synapse" Then
                Process.Start(p5)
            ElseIf resp = "aura" Then
                Process.Start(p6)
            ElseIf resp = "crpg" Then
                Process.Start(p7)
            ElseIf resp = "profilepic" Then
                Process.Start(p8)
            Else
                write("incorrect arguments", red, 40, 7)
                s(800, 40, 8)
                menu1()
            End If

        Catch ex As Exception
            Console.Write(ex)
            Console.ReadLine()
            functions1()
        End Try

        write(“done..”, white, 35, 3)
        s(300, 35, 4)
        menu1()

    End Function


    'add registry value
    Function add1()
        write(“reg name:”, white, 30, 1)
        Dim resp1 = Console.ReadLine()
        write(“what to save:”, white, 30, 3)
        Dim resp2 = Console.ReadLine()
        s(300, 30, 7)

        Try
            My.Computer.Registry.SetValue("HKEY_CURRENT_USER\menu", resp1, enc(resp2, 9))
        Catch ex As Exception
            Console.Write(ex)
            Console.ReadLine()
            menu1()
        End Try

        write(“done..”, white, 30, 6)
        s(300, 30, 7)
        menu1()

    End Function


    'read registry values
    Function read1()
        write(“reg name:”, white, 30, 1)
        Dim resp1 = Console.ReadLine()
        s(300, 30, 7)

        Try
            Dim read = My.Computer.Registry.GetValue("HKEY_CURRENT_USER\menu", resp1, Nothing)
            MsgBox(dec(read, 9))
        Catch ex As Exception
            Console.Write(ex)
            Console.ReadLine()
            menu1()
        End Try

        write(“done..”, white, 30, 6)
        s(300, 30, 7)
        menu1()

    End Function


    'delete registry values
    Function rem1()
        write(“reg name:”, white, 30, 1)
        Dim resp1 = Console.ReadLine()
        s(300, 30, 7)

        Try
            Dim s = My.Computer.Registry.CurrentUser.OpenSubKey("menu", True)
            s.DeleteValue(resp1)
        Catch ex As Exception
            Console.Write(ex)
            Console.ReadLine()
            menu1()
        End Try

        write(“done..”, white, 30, 6)
        s(300, 30, 7)
        menu1()

    End Function





End Module
