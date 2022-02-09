Imports System
Imports System.Object
Imports System.MarshalByRefObject
Imports System.Globalization
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.String



Module Module2

    Function md5f(ByVal Filename As String) As String

        Dim MD5 = System.Security.Cryptography.MD5.Create
        Dim Hash As Byte()
        Dim sb As New System.Text.StringBuilder

        Using st As New IO.FileStream(Filename, IO.FileMode.Open, IO.FileAccess.Read, IO.FileShare.Read)
            Hash = MD5.ComputeHash(st)
        End Using

        For Each b In Hash
            sb.Append(b.ToString("X2"))
        Next

        Return sb.ToString
    End Function


    Function rand(ini, f) As String
        Dim s As String = "abcdefghijklmnopqrstuvwxyz0123456789"
        Dim r As New Random()
        Dim sb As New System.Text.StringBuilder

        For i As Integer = ini To f
            Dim idx As Integer = r.Next(0, 35)
            sb.Append(s.Substring(idx, 1))
        Next

        Return sb.ToString
    End Function

    Function hash()
        Dim searchPattern As String = "*.*"
        For Each fileName As String In Directory.GetFiles(fdir, searchPattern, SearchOption.AllDirectories)
            Dim md5String = md5f(fileName)

            If FileExists(fdir + md5String + ".jpg") = True Then
                Do
                    md5String += rand(0, 8)
                Loop Until FileExists(fdir + md5String + ".jpg") = False
            End If

            Dim newfn = Path.Combine(fdir, md5String & ".jpg")

            Try
                File.Move(Path.Combine(fdir, fileName), newfn)

            Catch ex As Exception
                Console.Write(ex)
                Console.ReadLine()
                'System.Threading.Thread.Sleep(1000)

            End Try
            Console.WriteLine(vbCrLf + $"renamed: [ {fileName} ] > [ {newfn} ]")
        Next
        Console.WriteLine("done")
        System.Threading.Thread.Sleep(1000)

        main1()
    End Function

    Function random()
        Dim searchPattern As String = "*.*"
        Dim i As Integer = 0
        For Each fileName As String In Directory.GetFiles(fdir, searchPattern, SearchOption.AllDirectories)
            Dim str = rand(0, 20)

            If FileExists(fdir + str + ".jpg") = True Then
                Do
                    str = rand(0, 20)
                Loop Until FileExists(fdir + str + ".jpg") = False
            End If

            Dim newfn = Path.Combine(fdir, str & ".jpg")

            Try
                File.Move(Path.Combine(fdir, fileName), newfn)

            Catch ex As Exception
                Console.Write(ex)
                Console.ReadLine()
                'System.Threading.Thread.Sleep(1000)

            End Try
            i += 1
            Console.WriteLine(vbCrLf + $"renamed[{i}]: [ {fileName} ] > [ {newfn} ]")
        Next
        Console.WriteLine()
        Console.WriteLine("done")
        System.Threading.Thread.Sleep(1000)

        main1()
    End Function

    Function rename()
        Dim searchPattern As String = "*.*"
        Dim i As Integer = 0
        For Each fileName As String In Directory.GetFiles(fdir, searchPattern, SearchOption.AllDirectories)
            If FileExists(Path.Combine(fdir, i & ".jpg")) = True Then
                Do
                    i += 1
                Loop Until FileExists(Path.Combine(fdir, i & ".jpg")) = False
            End If

            Dim newfn = Path.Combine(fdir, i & ".jpg")

            Try

                File.Move(Path.Combine(fdir, fileName), newfn)
                i += 1

            Catch ex As Exception
                Console.WriteLine(ex)
                Console.ReadLine()
                'System.Threading.Thread.Sleep(1000)

            End Try
            Console.WriteLine(vbCrLf + $"renamed: [ {fileName} ] > [ {newfn} ]")
        Next
        Console.WriteLine("done")
        System.Threading.Thread.Sleep(1000)

        main1()
    End Function
End Module
