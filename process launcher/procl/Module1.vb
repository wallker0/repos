Imports System.Globalization

Module Module1

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

    '--------------------------------------------------------------------------------------------------

    Sub Main()

        Dim index As Integer

        If FileExists("test.txt") = False Then
            Console.WriteLine(vbCrLf + "name, please?")
            Dim name = Console.ReadLine()
            Dim currentDate = DateTime.Now
            My.Computer.FileSystem.WriteAllText("test.txt", name, False)
            Console.WriteLine($"{vbCrLf}welcome {name}, today is {currentDate:d} at {currentDate:t}")
            Console.Write(vbCrLf + "press any key to exit... ")
            Console.ReadKey(True)
            index = 1
            Console.Clear()
        Else
            index = 1
            Console.Clear()
        End If

        While index = 1

            Console.Title = "process launcher"
            Dim nome As String = My.Computer.FileSystem.ReadAllText("test.txt")
            Dim currentDate = DateTime.Now
            Console.BackgroundColor = ConsoleColor.Blue
            Console.ForegroundColor = ConsoleColor.White
            Console.WriteLine($"                     welcome, {nome} - {currentDate:d} | {currentDate:t}                   ")
            Console.BackgroundColor = ConsoleColor.Black
            Console.WriteLine("-------------------------------------------------------------------------------")
            Console.ForegroundColor = ConsoleColor.Green
            Console.WriteLine("                               avaible programs:                               ")
            Console.WriteLine("                  process1.exe   process2.exe   process3.exe                   ")
            Console.WriteLine("                  process4.exe   process5.exe   process6.exe                   ")
            Console.ForegroundColor = ConsoleColor.White
            Console.WriteLine("-------------------------------------------------------------------------------")
            Console.ForegroundColor = ConsoleColor.Green
            Console.WriteLine("                                startup/wakeup                                 ")
            Console.ForegroundColor = ConsoleColor.White
            Console.WriteLine("-------------------------------------------------------------------------------")
            Console.BackgroundColor = ConsoleColor.Blue
            Console.WriteLine("       commands: execute %% | quit | shutdown | restart | logoff | text        ")
            Console.BackgroundColor = ConsoleColor.Black
            Console.WriteLine("-------------------------------------------------------------------------------")
            Console.ForegroundColor = ConsoleColor.Yellow

            Dim execute = Console.ReadLine()

            If execute = "start process1.exe" Then
                System.Diagnostics.Process.Start("process1.bat")
                Console.WriteLine("process1.exe sucessfully started..")
                System.Threading.Thread.Sleep(500)
                Console.Clear()

            ElseIf execute = "start process2.exe" Then
                System.Diagnostics.Process.Start("process2.bat")
                Console.WriteLine("process2.exe sucessfully started..")
                System.Threading.Thread.Sleep(500)
                Console.Clear()

            ElseIf execute = "start process3.exe" Then
                System.Diagnostics.Process.Start("process3.bat")
                Console.WriteLine("process3.exe sucessfully started..")
                System.Threading.Thread.Sleep(500)
                Console.Clear()

            ElseIf execute = "start process4.exe" Then
                System.Diagnostics.Process.Start("process4.bat")
                Console.WriteLine("process4.exe sucessfully started..")
                System.Threading.Thread.Sleep(500)
                Console.Clear()

            ElseIf execute = "start process5.exe" Then
                System.Diagnostics.Process.Start("process5.bat")
                Console.WriteLine("process5.exe sucessfully started..")
                System.Threading.Thread.Sleep(500)
                Console.Clear()

            ElseIf execute = "start process6.exe" Then
                System.Diagnostics.Process.Start("process6.bat")
                Console.WriteLine("process6.exe sucessfully started..")
                System.Threading.Thread.Sleep(500)
                Console.Clear()

            ElseIf execute = "startup" Or "wakeup" Then
                System.Diagnostics.Process.Start("1.bat")
                System.Diagnostics.Process.Start("2.bat")
                System.Diagnostics.Process.Start("3.bat")
                System.Diagnostics.Process.Start("4.bat")
                System.Diagnostics.Process.Start("5.bat")
                System.Diagnostics.Process.Start("6.bat")
                Console.WriteLine("startup sucessfull..")
                System.Threading.Thread.Sleep(500)
                Console.Clear()

            ElseIf execute = "shutdown" Then
                Console.Clear()
                Console.WriteLine("goodbye..")
                System.Threading.Thread.Sleep(1000)
                System.Diagnostics.Process.Start("shutdown", "-s -t 00")
                Console.Clear()

            ElseIf execute = "restart" Then
                Console.Clear()
                Console.WriteLine("see ya..")
                System.Threading.Thread.Sleep(500)
                System.Diagnostics.Process.Start("shutdown", "-r -t 00")
                Console.Clear()

            ElseIf execute = "logoff" Then
                Console.Clear()
                Console.WriteLine("goodbye..")
                System.Threading.Thread.Sleep(500)
                System.Diagnostics.Process.Start("shutdown", "-l -t 00")
                Console.Clear()

            ElseIf execute = "text" Then
                Console.Clear()
                Console.WriteLine("tell me about your day:")
                Dim psic As String = Console.ReadLine()
                Console.WriteLine("what day`s today?")
                Dim day = Console.ReadLine()
                My.Computer.FileSystem.WriteAllText(day + ".dat", psic, True)
                Console.WriteLine("thank u.. be well..")
                System.Threading.Thread.Sleep(400)
                Console.Clear()

            Else
                Console.Clear()

            End If

            ' If index is 0, exit the loop.
            If index = 0 Then
                Exit While
            End If
        End While

    End Sub

End Module
