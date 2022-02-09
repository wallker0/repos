Imports System.Globalization

Imports System.Object
Imports System.MarshalByRefObject
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.Collections

Module Module1

    Dim index As Integer
    Dim p As New csaves()
    Dim x As New Xml.Serialization.XmlSerializer(p.GetType)

    Function FileExists(FilePath As String) As Boolean
        Dim TestStr As String
        TestStr = ""
        On Error Resume Next
        TestStr = Dir(FilePath)
        On Error GoTo 0
        If TestStr = "" Then
            FileExists = False
        Else
            FileExists = True
        End If
    End Function

    Function Save()
        Dim sw As StreamWriter = New StreamWriter("saves\ficha1.dat")
        x.Serialize(sw, p)
        System.Threading.Thread.Sleep(500)
        Console.ForegroundColor = ConsoleColor.Green
        Console.WriteLine("d o n e !")
        System.Diagnostics.Process.Start("ficha.exe")
        index = 0
        Console.Clear()
    End Function

    '=====================================================================================================
    Sub Main()

        If FileExists("saves\ficha1.dat") = False Then

            System.IO.Directory.CreateDirectory("saves\")
            Dim path As String = "saves\inventory.inv"
            Dim fs As FileStream = File.Create(path)
            Dim path2 As String = "saves\lore.dat"
            Dim fs2 As FileStream = File.Create(path2)
            Dim path3 As String = "saves\aprim.dat"
            Dim fs3 As FileStream = File.Create(path3)
            Dim path4 As String = "saves\peric.dat"
            Dim fs4 As FileStream = File.Create(path4)

            'name=========================================================================================
            Console.WriteLine(vbCrLf + "name?")
            Dim charname As String = Console.ReadLine
            p.name = charname
            Console.WriteLine($"   welcome {p.name}, today is [ ? ? ? ? ? ? ? ? ? ] of [ ? ? ? ? ]")
            Console.Clear()

            'idade========================================================================================
            Console.WriteLine(vbCrLf + "idade?")
            Dim charidade As String = Console.ReadLine
            p.idade = charidade
            Console.Clear()

            'city=========================================================================================
            Console.WriteLine(vbCrLf + "city?")
            Dim charcity As String = Console.ReadLine
            p.city = charcity
            Console.Clear()

            'level========================================================================================
            Console.WriteLine(vbCrLf + "level?")
            Dim charlevel As String = Console.ReadLine
            p.level = charlevel
            Console.Clear()

            'faith========================================================================================
            Console.WriteLine(vbCrLf + "fé?")
            Dim charfaith As String = Console.ReadLine
            p.faith = charfaith
            Console.Clear()

            'forca========================================================================================
            Console.WriteLine(vbCrLf + "forca?")
            Dim charfor As String = Console.ReadLine
            p.forca = charfor
            Console.Clear()

            'cons=========================================================================================
            Console.WriteLine(vbCrLf + "constituicao?")
            Dim charcon As String = Console.ReadLine
            p.con = charcon
            Console.Clear()

            'des==========================================================================================
            Console.WriteLine(vbCrLf + "destreza?")
            Dim chardes As String = Console.ReadLine
            p.des = chardes
            Console.Clear()

            'agi==========================================================================================
            Console.WriteLine(vbCrLf + "agilidade?")
            Dim charagi As String = Console.ReadLine
            p.agi = charagi
            Console.Clear()

            'int==========================================================================================
            Console.WriteLine(vbCrLf + "inteligencia?")
            Dim charint As String = Console.ReadLine
            p.int = charint
            Console.Clear()

            'will=========================================================================================
            Console.WriteLine(vbCrLf + "will?")
            Dim charwill As String = Console.ReadLine
            p.will = charwill
            Console.Clear()

            'per==========================================================================================
            Console.WriteLine(vbCrLf + "percepcao?")
            Dim charper As String = Console.ReadLine
            p.per = charper
            Console.Clear()

            'car==========================================================================================
            Console.WriteLine(vbCrLf + "carisma?")
            Dim charcar As String = Console.ReadLine
            p.car = charcar
            Console.Clear()

            'save=========================================================================================
            x.Serialize(Console.Out, p)
            p.hp = p.forca + p.con / 2
            Console.Write(vbCrLf + "press any key to continue... ")
            Console.ReadKey(True)
            Save()
            Console.Clear()

        Else

            'import=======================================================================================
            Using sr As New StreamReader("saves\ficha1.dat")
                p = x.Deserialize(sr)
            End Using
            index = 1
            Console.Clear()

        End If

        While index = 1

            Console.Clear()
            Console.SetWindowSize(90, 44)

            Console.BufferHeight = 44
            Console.BufferWidth = 90

            Console.Title = "r p g"

            Console.ForegroundColor = ConsoleColor.White
            Console.BackgroundColor = ConsoleColor.Blue
            Console.SetCursorPosition(0, 0)
            Console.WriteLine($"           welcome, {p.name} - [ u n d e f i n e d ]  |  [ ? ? ? ? ]                       ")

            Console.BackgroundColor = ConsoleColor.Black
            Console.ForegroundColor = ConsoleColor.Green
            Console.SetCursorPosition(0, 1)
            Console.WriteLine("|===========[pts]=================|===================[hab]=============================|")

            Console.SetCursorPosition(34, 2)
            Console.WriteLine("|")
            Console.SetCursorPosition(34, 3)
            Console.WriteLine("|")
            Console.SetCursorPosition(0, 4)
            Console.WriteLine("|")
            Console.SetCursorPosition(0, 5)
            Console.WriteLine("|==================================")
            Console.SetCursorPosition(34, 4)
            Console.WriteLine("|")
            Console.SetCursorPosition(34, 5)
            Console.WriteLine("|=====================================================|")
            Console.SetCursorPosition(88, 2)
            Console.WriteLine("|")
            Console.SetCursorPosition(88, 3)
            Console.WriteLine("|")
            Console.SetCursorPosition(88, 4)
            Console.WriteLine("|")
            Console.SetCursorPosition(0, 2)
            Console.WriteLine("|")
            Console.SetCursorPosition(0, 3)
            Console.WriteLine("|")
            Console.SetCursorPosition(0, 4)
            Console.WriteLine("|")


            Console.SetCursorPosition(2, 2)
            Console.WriteLine($"hp:    {p.forca + p.con / 2}")

            Console.SetCursorPosition(2, 3)
            Console.WriteLine($"level: {p.level}")

            Console.SetCursorPosition(15, 4)
            Console.WriteLine($"inici: {p.agi}[{p.agi * 4}%]")

            Console.SetCursorPosition(2, 4)
            Console.WriteLine($"idade: {p.idade}")

            Console.SetCursorPosition(15, 2)
            Console.WriteLine($"faith: {p.faith} ")

            Console.SetCursorPosition(15, 3)
            Console.WriteLine($"city:  {p.city}")

            Console.SetCursorPosition(38, 2)
            Console.WriteLine($"for: {p.forca}[{p.forca * 4}%]")

            Console.SetCursorPosition(69, 2)
            Console.WriteLine($"agi:  {p.agi}[{p.agi * 4}%]")

            Console.SetCursorPosition(53, 2)
            Console.WriteLine($"per:  {p.per}[{p.per * 4}%]")

            Console.SetCursorPosition(38, 3)
            Console.WriteLine($"con: {p.con}[{p.con * 4}%]")

            Console.SetCursorPosition(69, 3)
            Console.WriteLine($"int:  {p.int}[{p.int * 4}%]")

            Console.ForegroundColor = ConsoleColor.Gray
            Console.SetCursorPosition(69, 4)
            Console.WriteLine($"pontos:  {(5 * p.idade) + 5 * p.int}")

            Console.ForegroundColor = ConsoleColor.Green
            Console.SetCursorPosition(53, 3)
            Console.WriteLine($"car:  {p.car}[{p.car * 4}%]")

            Console.SetCursorPosition(38, 4)
            Console.WriteLine($"des: {p.des}[{p.des * 4}%]")

            Console.SetCursorPosition(53, 4)
            Console.WriteLine($"will: {p.will}[{p.will * 4}%]")

            Console.SetCursorPosition(0, 7)
            Dim peric As String = My.Computer.FileSystem.ReadAllText("saves\peric.dat")
            Console.WriteLine(peric)
            Console.WriteLine($"                                                                               ")
            Dim aprim As String = My.Computer.FileSystem.ReadAllText("saves\aprim.dat")
            Console.WriteLine(aprim)
            Console.WriteLine($"                                                                               ")
            Console.ForegroundColor = ConsoleColor.Gray
            Dim loreee As String = My.Computer.FileSystem.ReadAllText("saves\lore.dat")
            Console.WriteLine(loreee)

            Console.SetCursorPosition(0, 40)
            Console.ForegroundColor = ConsoleColor.White
            Console.WriteLine("-----------------------------------------------------------------------------------------")
            Console.BackgroundColor = ConsoleColor.Blue
            Console.WriteLine("====================== comandos: edit %% | anotar | view %% | quit ======================")
            Console.BackgroundColor = ConsoleColor.Black
            Console.WriteLine("-----------------------------------------------------------------------------------------")
            Console.ForegroundColor = ConsoleColor.Yellow

            Dim execute = Console.ReadLine()

            If execute = "edit name" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"novo nome? antigo[{p.name}]")
                Dim charname As String = Console.ReadLine
                p.name = charname
                Save()

            ElseIf execute = "edit faith" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"novo faith? antigo[{p.faith}]")
                Dim charfaith As String = Console.ReadLine
                p.faith = charfaith
                Save()

            ElseIf execute = "edit level" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"novo level? antigo[{p.level}]")
                Dim charlevel As String = Console.ReadLine
                p.level = charlevel
                Save()

            ElseIf execute = "edit city" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"nova cidade? antiga[{p.city}]")
                Dim charcity As String = Console.ReadLine
                p.city = charcity
                Save()

            ElseIf execute = "edit for" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"nova forca? antiga[{p.forca}]")
                Dim charfor As String = Console.ReadLine
                p.forca = charfor
                Save()

            ElseIf execute = "edit con" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"nova constituicao? antiga[{p.con}]")
                Dim charcon As String = Console.ReadLine
                p.con = charcon
                Save()

            ElseIf execute = "edit des" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"nova destreza? antiga[{p.des}]")
                Dim chardes As String = Console.ReadLine
                p.des = chardes
                Save()

            ElseIf execute = "edit agi" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"nova agilidade? antiga[{p.agi}]")
                Dim charagi As String = Console.ReadLine
                p.agi = charagi
                Save()

            ElseIf execute = "edit int" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"nova inteligencia? antiga[{p.int}]")
                Dim charint As String = Console.ReadLine
                p.int = charint
                Save()

            ElseIf execute = "edit will" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"novo will? antigo[{p.will}]")
                Dim charwill As String = Console.ReadLine
                p.will = charwill
                Save()

            ElseIf execute = "edit per" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"nova percepcao? antiga[{p.per}]")
                Dim charper As String = Console.ReadLine
                p.per = charper
                Save()

            ElseIf execute = "edit car" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"novo carisma? antigo[{p.car}]")
                Dim charcar As String = Console.ReadLine
                p.car = charcar
                Save()

            ElseIf execute = "edit idade" Then
                Console.Clear()
                Console.WriteLine(vbCrLf + $"nova idade? antigo[{p.idade}]")
                Dim charidade As String = Console.ReadLine
                p.idade = charidade
                Save()

            ElseIf execute = "view inventory" Then
                Console.Clear()
                Dim inventario As String = My.Computer.FileSystem.ReadAllText("saves\inventory.inv")
                Console.WriteLine(inventario)
                Console.WriteLine("press any key to return... ")
                Console.ReadKey(True)
                Console.Clear()

            ElseIf execute = "edit lore.dat" Then
                If FileExists("saves\lore.dat") = False Then
                    Console.Clear()
                    Console.Write("there is no lore to show yet... ")
                    Console.WriteLine("press any key to return... ")
                    Console.ReadKey(True)
                    Console.Clear()
                Else
                    Console.WriteLine("tell me your lore: ")
                    Dim loree As String = Console.ReadLine
                    My.Computer.FileSystem.WriteAllText("saves\lore.dat", loree, False)
                    Save()
                End If

            ElseIf execute = "view lore.dat" Then
                If FileExists("saves\lore.dat") = False Then
                    Console.Clear()
                    Console.Write("there is no lore to show yet... ")
                    Console.WriteLine("press any key to return... ")
                    Console.ReadKey(True)
                    Console.Clear()
                Else
                    Console.Clear()
                    Console.WriteLine(loreee)
                    Console.WriteLine("press any key to return... ")
                    Console.ReadKey(True)
                    Console.Clear()
                End If

            ElseIf execute = "edit aprim.dat" Then
                If FileExists("saves\aprim.dat") = False Then
                    Console.Clear()
                    Console.Write("there is nothing to show yet... ")
                    Console.WriteLine("press any key to return... ")
                    Console.ReadKey(True)
                    Console.Clear()
                Else
                    Console.WriteLine("aprimoramentos? (positivos e negativos com valores, modelo  `aprim(+/-valor)`)")
                    Dim aprimo As String = Console.ReadLine
                    My.Computer.FileSystem.WriteAllText("saves\aprim.dat", aprimo, False)
                    Save()
                End If

            ElseIf execute = "edit peric.dat" Then
                If FileExists("saves\peric.dat") = False Then
                    Console.Clear()
                    Console.Write("there is nothing to show yet... ")
                    Console.WriteLine("press any key to return... ")
                    Console.ReadKey(True)
                    Console.Clear()
                Else
                    Console.WriteLine("pericias? modelo  `pericia: valor[porcentagem]`)")
                    Dim pericc As String = Console.ReadLine
                    My.Computer.FileSystem.WriteAllText("saves\peric.dat", pericc, False)
                    Save()
                End If

            ElseIf execute = "view aprim.dat" Then
                If FileExists("saves\aprim.dat") = False Then
                    Console.Clear()
                    Console.Write("there is nothing to show yet... ")
                    Console.WriteLine("press any key to return... ")
                    Console.ReadKey(True)
                    Console.Clear()
                Else
                    Console.Clear()
                    Console.WriteLine(aprim)
                    Console.WriteLine("press any key to return... ")
                    Console.ReadKey(True)
                    Console.Clear()
                End If

            ElseIf execute = "anotar" Then
                Console.WriteLine("nome do arquivo? %modelo%")
                Dim arq As String = Console.ReadLine
                If FileExists(arq) = True Then
                    Console.Clear()
                    Console.Write("file already exists... ")
                    Console.WriteLine("press any key to return... ")
                    Console.ReadKey(True)
                    Console.Clear()
                Else
                    Console.WriteLine("o que deseja anotar?")
                    Dim anot As String = Console.ReadLine
                    My.Computer.FileSystem.WriteAllText("saves\" + arq + ".dat", anot, False)
                    Save()
                End If

            ElseIf execute = "view photo" Then
                Dim arg6 As String = "saves\photo.jpeg"
                If FileExists(arg6) = True Then
                    Process.Start(arg6)
                Else
                    Console.WriteLine("there is no photo")
                    Console.WriteLine("press any key to return... ")
                    Console.ReadKey(True)
                    Console.Clear()
                End If

            ElseIf execute = "view" Then
                Console.WriteLine("o que deseja ver? %modelo.dat%")
                Dim files = Directory.GetFiles("saves\")
                For Each foundFile As String In files
                    Console.WriteLine(foundFile)
                Next
                Dim anot2 As String = Console.ReadLine
                Console.Clear()
                Dim anot3 As String = My.Computer.FileSystem.ReadAllText("saves\" + anot2)
                Console.WriteLine(anot3)
                Console.WriteLine("press any key to return... ")
                Console.ReadKey(True)


            ElseIf execute = "quit" Then
                Dim sw As StreamWriter = New StreamWriter("saves\ficha1.dat")
                x.Serialize(sw, p)
                index = 0

            Else

                Console.Clear()

            End If

            ' If index is 0, exit the loop.
            If Index = 0 Then
                Exit Sub
            End If
        End While

    End Sub

End Module
