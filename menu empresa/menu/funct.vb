'funct.vb
'credits to @wallker




Option Explicit On


Imports System.Net
Imports HtmlAgilityPack

Imports System.Globalization

Imports System.Object
Imports System.MarshalByRefObject
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.ComponentModel.Component
Imports System.Net.WebClient


Module funct


    Function decCH(InputString As String, ValueToAdd As Integer) As String
        Dim OutputString As String = String.Empty
        Dim c As Char
        For i = 0 To Len(InputString) - 1
            c = InputString.Substring(i, 1)
            OutputString += Chr(Asc(c) + ValueToAdd)
        Next

        Return OutputString
    End Function



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


    Function dolar()

        'WIP WIP WIP 

    End Function


    Public d As New cvar2()
    Public xx As New Xml.Serialization.XmlSerializer(d.GetType)

    Public d2 As New cvar3()
    Public xx2 As New Xml.Serialization.XmlSerializer(d.GetType)



    'registrar empresa
    Function regemp1()
        write(“nome da empresa: ”, white, 65, 2)
        d.nome = Console.ReadLine()
        write(“telefone da empresa: ”, white, 65, 4)
        d.telef = Console.ReadLine()
        write(“endereco da empresa: ”, white, 65, 6)
        d.ender = Console.ReadLine()
        write(“valor devido: ”, white, 65, 8)
        d.valor = Console.ReadLine()
        write(“tipo: [pago/naopago/aberto]  ”, white, 65, 10)
        Dim resp5 = Console.ReadLine()
        d.pgo = resp5
        s(400, 65, 12)

        Try
            Dim path As String
            If resp5 = "pago" Then
                path = "database\empr\pagas\"

            ElseIf resp5 = "naopago" Then
                path = "database\empr\naopagas\"

            ElseIf resp5 = "aberto" Then
                path = "database\empr\emaberto\"

            End If

            Dim sw As StreamWriter = New StreamWriter(path + d.nome + ".dat")
            xx.Serialize(sw, d)
            sw.Close()

        Catch ex As Exception
            Console.Write(ex)
            Console.ReadLine()
            menu1()
        End Try

        write(“done..”, white, 65, 14)
        s(400, 65, 15)
        menu1()

    End Function


    'registrar pagamento
    Function regpag1()
        write(“nome da empresa: ”, white, 65, 2)
        d2.nome = Console.ReadLine()
        write(“valor pago: ”, white, 65, 4)
        d2.valor = Console.ReadLine()
        write(“data: ”, white, 65, 6)
        d2.data = Console.ReadLine()
        s(400, 65, 8)

        Try
            Dim path As String = "database\pagtos\"

            Dim sw As StreamWriter = New StreamWriter(path + d2.nome + ".dat")
            xx2.Serialize(sw, d2)
            sw.Close()

        Catch ex As Exception
            Console.Write(ex)
            Console.ReadLine()
            menu1()
        End Try

        write(“done..”, white, 65, 10)
        s(400, 65, 11)
        menu1()

    End Function

    'registrar anotacao
    Function reganot1()
        write(“titulo: ”, white, 65, 2)
        Dim resp1 = Console.ReadLine()
        write(“o que deseja anotar? ”, white, 65, 4)
        Dim resp2 = Console.ReadLine()

        s(400, 65, 6)

        Try
            Dim path As String = "database\anot\"
            File.WriteAllText(path + resp1 + ".dat", resp2)

        Catch ex As Exception
            Console.Write(ex)
            Console.ReadLine()
            menu1()
        End Try

        write(“done..”, white, 65, 8)
        s(400, 65, 9)
        menu1()

    End Function


    'lista pagas
    Function lpagas1()
        Dim files() As String = IO.Directory.GetFiles("database\empr\pagas\")
        Console.WriteLine()

        For Each file As String In files
            Console.WriteLine(file)
        Next

        Console.ReadLine()
        menu1()
    End Function


    'lista nao cobradas
    Function lncobradas1()
        Dim files() As String = IO.Directory.GetFiles("database\empr\naopagas\")
        Console.WriteLine()

        For Each file As String In files
            Console.WriteLine(file)
        Next

        Console.ReadLine()
        menu1()
    End Function


    'lista aguardando
    Function laguardando1()
        Dim files() As String = IO.Directory.GetFiles("database\empr\emaberto\")
        Console.WriteLine()

        For Each file As String In files
            Console.WriteLine(file)
        Next

        Console.ReadLine()
        menu1()
    End Function


    'lista extrato
    Function lextr1()
        Dim files() As String = IO.Directory.GetFiles("database\pagtos\")
        Console.WriteLine()

        For Each file As String In files
            Console.WriteLine(file)
        Next

        Console.ReadLine()
        menu1()
    End Function


    'lista anotacoes
    Function lanot1()
        Dim files() As String = IO.Directory.GetFiles("database\anot\")
        Console.WriteLine()

        For Each file As String In files
            Console.WriteLine(file)
        Next

        Console.ReadLine()
        menu1()
    End Function


    'abrir empresa por nome
    Function abrirnome1()
        write(“tipo: [pago/naopago/aberto]  ”, white, 65, 2)
        Dim resp1 = Console.ReadLine()
        write(“nome da empresa: ”, white, 65, 4)
        Dim resp2 = Console.ReadLine()
        s(400, 65, 6)

        Dim path As String

        If resp1 = "pago" Then
            path = "database\empr\pagas\"

        ElseIf resp1 = "naopago" Then
            path = "database\empr\naopagas\"

        ElseIf resp1 = "aberto" Then
            path = "database\empr\emaberto\"
        End If


        Using sr As New StreamReader(path + resp2 + ".dat")
            d = xx.Deserialize(sr)
        End Using

        write(d.nome, white, 65, 7)
        write(d.telef, white, 65, 8)
        write(d.ender, white, 65, 9)
        write(d.valor, white, 65, 10)
        write(d.pgo, white, 65, 11)

        Console.ReadLine()
        menu1()
    End Function


    'abrir extrato por nome
    Function abrirnome2()
        write(“nome do extrato: ”, white, 65, 4)
        Dim resp2 = Console.ReadLine()
        s(400, 65, 6)


        Using sr As New StreamReader("database\pagtos\" + resp2 + ".dat")
            d2 = xx2.Deserialize(sr)
        End Using

        write(d2.nome, white, 65, 7)
        write(d2.valor, white, 65, 8)
        write(d2.data, white, 65, 9)

        Console.ReadLine()
        menu1()
    End Function


    'abrir anotacao por nome
    Function abrirnome3()
        write(“nome da anotacao: ”, white, 65, 4)
        Dim resp2 = Console.ReadLine()
        s(400, 65, 6)

        Dim sr As String = "database\anot\" + resp2 + ".dat"
        write(File.ReadAllText(sr), white, 1, 16)

        Console.ReadLine()
        menu1()
    End Function


    'confirmar pagamento
    Function confpgto1()
        write(“tipo: [naopago/aberto]  ”, white, 65, 2)
        Dim resp1 = Console.ReadLine()
        write(“nome da empresa: ”, white, 65, 4)
        Dim resp2 = Console.ReadLine()
        s(400, 65, 6)

        Dim path As String

        If resp1 = "naopago" Then
            path = "database\empr\naopagas\"

        ElseIf resp1 = "aberto" Then
            path = "database\empr\emaberto\"
        End If

        Using sr As New StreamReader(path + resp2 + ".dat")
            d = xx.Deserialize(sr)
        End Using

        d.pgo = "pago"

        Dim sw As StreamWriter = New StreamWriter("database\empr\pagas\" + d.nome + ".dat")
        xx.Serialize(sw, d)
        sw.Close()

        write(“done..”, white, 65, 6)
        s(700, 65, 7)
        menu1()
    End Function


    'colocar em aberto
    Function colaberto1()
        write(“nome da empresa: ”, white, 65, 2)
        Dim resp2 = Console.ReadLine()
        s(400, 65, 6)

        Dim path As String = "database\empr\naopagas\"

        Using sr As New StreamReader(path + resp2 + ".dat")
            d = xx.Deserialize(sr)
        End Using

        d.pgo = "aberto"

        Dim sw As StreamWriter = New StreamWriter("database\empr\emaberto\" + d.nome + ".dat")
        xx.Serialize(sw, d)
        sw.Close()

        write(“done..”, white, 65, 6)
        s(700, 65, 7)
        menu1()
    End Function


    'apagar empresa
    Function delempr1()
        write(“nome da empresa: ”, white, 65, 2)
        Dim resp2 = Console.ReadLine()
        write(“tipo: [pago/naopago/aberto]  ”, white, 65, 4)
        Dim resp1 = Console.ReadLine()
        s(400, 65, 6)

        Dim path As String

        If resp1 = "pago" Then
            path = "database\empr\pagas\"

        ElseIf resp1 = "naopago" Then
            path = "database\empr\naopagas\"

        ElseIf resp1 = "aberto" Then
            path = "database\empr\emaberto\"
        End If

        File.Delete(path + resp2 + ".dat")
        write(“done..”, white, 65, 6)
        s(700, 65, 7)
        menu1()
    End Function







End Module
