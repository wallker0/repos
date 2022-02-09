'repo.vb
'credits to @wallker



Module repo

    Public index As Integer = 1
    Public p As New clsPerson()
    Public x As New Xml.Serialization.XmlSerializer(p.GetType)

    Public black = ConsoleColor.Black
    Public white = ConsoleColor.White

    Public blue = ConsoleColor.Blue
    Public cyan = ConsoleColor.Cyan
    Public gray = ConsoleColor.Gray
    Public green = ConsoleColor.Green
    Public magenta = ConsoleColor.Magenta
    Public red = ConsoleColor.Red
    Public yellow = ConsoleColor.Yellow

    Public dblue = ConsoleColor.DarkBlue
    Public dcyan = ConsoleColor.DarkCyan
    Public dgray = ConsoleColor.DarkGray
    Public dgreen = ConsoleColor.DarkGreen
    Public dmagenta = ConsoleColor.DarkMagenta
    Public dred = ConsoleColor.DarkRed
    Public dyellow = ConsoleColor.DarkYellow


    Function clear()
        Console.Clear()
    End Function

    Function pause()
        Console.Write(vbCrLf + vbCrLf + "press any key to continue... ")
        Console.ReadKey(True)
    End Function

    Function writeto(a, b)
        System.IO.File.AppendAllText(a, b)
    End Function

    Function wsize(y, x)
        Console.SetWindowSize(x, y)
    End Function

    Function bheight(x)
        Console.BufferHeight = x
    End Function

    Function bwidth(x)
        Console.BufferWidth = x
    End Function

    Function ctitle(x)
        Console.Title = x
    End Function

    Function cpos(y, x)
        Console.SetCursorPosition(x, y)
    End Function

    Function bgcolor(x)
        Console.BackgroundColor = x
    End Function

    Function txtcolor(x)
        Console.ForegroundColor = x
    End Function

    Function open(x)
        Process.Start(x)
    End Function

    Function InRange(ByVal value As Decimal, ByVal max As Decimal, Optional ByVal min As Decimal = 0) As Decimal
        If (value >= min AndAlso value <= max) Then
            Return True
        End If
    End Function


    'filecheck
    Function fileexists(FilePath As String) As Boolean
        Dim a As String
        a = ""
        On Error Resume Next
        a = Dir(FilePath)
        On Error GoTo 0
        If a = "" Then
            fileexists = False
        Else
            fileexists = True
        End If
    End Function


    'sleep
    Function s(t As Integer, y As Integer, x As Integer)
        Try
            cpos(y, x)
            System.Threading.Thread.Sleep(t / 3)
            Console.Write(“.”)
            System.Threading.Thread.Sleep(t / 3)
            Console.Write(“.”)
            System.Threading.Thread.Sleep(t / 3)
            Console.Write(“.”)
        Catch ex As Exception
            Console.Write(ex)
            pause()
        End Try
    End Function


    'console write
    Function write(s, colorfg, colorbg, Optional y = 0, Optional x = 0, Optional inloop = False)
        Try
            txtcolor(colorfg)
            bgcolor(colorbg)
            If inloop = True Then
                Dim y0 = Console.CursorTop
                Dim x0 = Console.CursorLeft
                x0 = y0 = 0
                cpos(y0 + y, x0 + x)
            Else
                cpos(y, x)
            End If
            Console.Write(s)
            Console.ResetColor()
        Catch ex As Exception
            Console.Write(ex)
            pause()
        End Try
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



End Module