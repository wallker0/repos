'data.vb
'credits to @wallker



Module data

    'reg new value
    Function regnew()
        clear()
        write($"type the value to register ( in btc ) : ", yellow, black, 1, 0)
        Dim v1 As Decimal
        Dim v2 = Console.ReadLine()
        write($"type the tax value ( in btc ) : ", yellow, black, 3, 0)
        Dim t1 As Decimal
        Dim t2 = Console.ReadLine()
        Decimal.TryParse(v2, v1)
        Decimal.TryParse(t2, t1)
        Dim tot As String = CDec(v1) - CDec(t1)
        writeto("data\37157", vbCrLf + tot)
        p.wbtc += tot
        save()
    End Function

    'remove value
    Function debnew()
        clear()
        write($"type the value to remove ( in btc ) : ", yellow, black, 1, 0)
        Dim v1 As Decimal
        Dim v2 = Console.ReadLine()
        write($"type the tax value ( in btc ) : ", yellow, black, 3, 0)
        Dim t1 As Decimal
        Dim t2 = Console.ReadLine()
        Decimal.TryParse(v2, v1)
        Decimal.TryParse(t2, t1)
        Dim tot As String = CDec(v1) - CDec(t1)
        writeto("data\37158", vbCrLf + tot)
        p.wbtc -= v1
        save()
    End Function

    'print values added
    Function walletd()
        clear()
        wsize(30, 60)
        Dim line As String
        write("current entry list", yellow, black, 1, 0)
        Using reader As New System.IO.StreamReader("data\37157")
            While Not reader.EndOfStream
                Console.BufferHeight += 1
                line = reader.ReadLine
                write(" + " & line & " / R$ " & Math.Round(line * p.btc, 2), white, black, 1, 0, True)
            End While
        End Using
        pause()
    End Function

    'print values debited
    Function walletw()
        clear()
        wsize(30, 60)
        Dim line As String
        write("current removed list", yellow, black, 1, 0)
        Using reader As New System.IO.StreamReader("data\37158")
            While Not reader.EndOfStream
                Console.BufferHeight += 1
                line = reader.ReadLine
                write(" - " & line & " / R$ " & Math.Round(line * p.btc, 2), white, black, 1, 0, True)
            End While
        End Using
        pause()
    End Function

    'brute avrg
    Function lavrg()
        clear()
        wsize(15, 60)
        Dim v As Decimal = Math.Round(((sumv2() * p.btc) / days2()), 2)
        write("data avrg                                                   ", black, yellow, 1, 0)
        write("1d   :  R$ " & (v) & "  [+/-%25]  [" & Math.Round(v + (v * 0.25), 2) & "]  [" & Math.Round(v - (v * 0.25), 2) & "]", white, black, 3, 0)
        write("7d   :  R$ " & (v * 7) & "  [+/-%25]  [" & Math.Round((v * 7) + ((v * 7) * 0.25), 2) & "]  [" & Math.Round((v * 7) - ((v * 7) * 0.25), 2) & "]", white, black, 4, 0)
        write("30d  :  R$ " & (v * 30) & "  [+/-%25]  [" & Math.Round((v * 30) + ((v * 30) * 0.25), 2) & "]  [" & Math.Round((v * 30) - ((v * 30) * 0.25), 2) & "]", white, black, 5, 0)
        write("60d  :  R$ " & (v * 60) & "  [+/-%25]  [" & Math.Round((v * 60) + ((v * 60) * 0.25), 2) & "]  [" & Math.Round((v * 60) - ((v * 60) * 0.25), 2) & "]", white, black, 6, 0)
        write("90d  :  R$ " & (v * 90) & "  [+/-%25]  [" & Math.Round((v * 90) + ((v * 90) * 0.25), 2) & "]  [" & Math.Round((v * 90) - ((v * 90) * 0.25), 2) & "]", white, black, 7, 0)
        write("180d :  R$ " & (v * 180) & "  [+/-%25]  [" & Math.Round((v * 180) + ((v * 180) * 0.25), 2) & "]  [" & Math.Round((v * 180) - ((v * 180) * 0.25), 2) & "]", white, black, 8, 0)
        write("360d :  R$ " & (v * 360) & "  [+/-%25]  [" & Math.Round((v * 360) + ((v * 360) * 0.25), 2) & "]  [" & Math.Round((v * 360) - ((v * 360) * 0.25), 2) & "]", white, black, 9, 0)
        pause()
    End Function

    'avrg
    Function avrg()
        clear()
        wsize(15, 60)
        Dim v As Decimal = Math.Round((((sumv2() * p.btc) / days2()) - (p.pwr / 30)), 2)
        write("liquid data avrg                                            ", black, yellow, 1, 0)
        write("1d   :  R$ " & (v) & "  [+/-%25]  [" & Math.Round(v + (v * 0.25), 2) & "]  [" & Math.Round(v - (v * 0.25), 2) & "]", white, black, 3, 0)
        write("7d   :  R$ " & (v * 7) & "  [+/-%25]  [" & Math.Round((v * 7) + ((v * 7) * 0.25), 2) & "]  [" & Math.Round((v * 7) - ((v * 7) * 0.25), 2) & "]", white, black, 4, 0)
        write("30d  :  R$ " & (v * 30) & "  [+/-%25]  [" & Math.Round((v * 30) + ((v * 30) * 0.25), 2) & "]  [" & Math.Round((v * 30) - ((v * 30) * 0.25), 2) & "]", white, black, 5, 0)
        write("60d  :  R$ " & (v * 60) & "  [+/-%25]  [" & Math.Round((v * 60) + ((v * 60) * 0.25), 2) & "]  [" & Math.Round((v * 60) - ((v * 60) * 0.25), 2) & "]", white, black, 6, 0)
        write("90d  :  R$ " & (v * 90) & "  [+/-%25]  [" & Math.Round((v * 90) + ((v * 90) * 0.25), 2) & "]  [" & Math.Round((v * 90) - ((v * 90) * 0.25), 2) & "]", white, black, 7, 0)
        write("180d :  R$ " & (v * 180) & "  [+/-%25]  [" & Math.Round((v * 180) + ((v * 180) * 0.25), 2) & "]  [" & Math.Round((v * 180) - ((v * 180) * 0.25), 2) & "]", white, black, 8, 0)
        write("360d :  R$ " & (v * 360) & "  [+/-%25]  [" & Math.Round((v * 360) + ((v * 360) * 0.25), 2) & "]  [" & Math.Round((v * 360) - ((v * 360) * 0.25), 2) & "]", white, black, 9, 0)
        pause()
    End Function

    'store data
    Function store()
        clear()
        Try
            write("type the file name [ DDMM-DDMM.YY ] :  ", yellow, black, 1, 0)
            Dim resp = Console.ReadLine()
            Dim v As String = p.wbtc
            writeto("data\37158", vbCrLf + v)
            Dim contents As String = String.Empty
            If Not System.IO.File.Exists("data\37159") Then
                System.IO.File.Create("data\37159").Dispose()
                writeto("data\37159", 0)
            End If
            Using reader As System.IO.TextReader = New System.IO.StreamReader("data\37157")
                contents = reader.ReadToEnd()
                Using writer As New System.IO.StreamWriter("data\37159", System.IO.FileMode.Append)
                    writer.Write(contents)
                End Using
            End Using
            System.IO.Directory.CreateDirectory("data\str\" & resp)
            System.IO.Directory.Move("data\37157", "data\str\" & resp & "\37157")
            System.IO.File.Create("data\37157").Dispose()
            writeto("data\37157", 0)
            p.wbtc = 0
            save()
        Catch ex As Exception
            Console.WriteLine("wrong filename")
            pause()
        End Try
    End Function

    'list data
    Function ldata()
        clear()
        wsize(30, 60)
        write("available files :", yellow, black, 1, 0)
        Try
            For Each dr As String In System.IO.Directory.GetDirectories("data\str\")
                write(dr, white, black, 1, 0, True)
            Next
        Catch ex As Exception
            Console.WriteLine("no data to show")
            pause()
        End Try
        Console.WriteLine(vbCrLf + vbCrLf + "read data from any of them? [blank to go back]")
        Console.WriteLine("[file name as DDMM-DDMM.YY to load]")
        Dim rd = Console.ReadLine()
        Dim line As String
        clear()
        If rd = "" Then
            main1()
        End If
        Try
            write("data\str\" & rd & "\", yellow, black, 1, 0)
            Using reader As New System.IO.StreamReader("data\str\" & rd & "\37157")
                While Not reader.EndOfStream
                    Console.BufferHeight += 1
                    line = reader.ReadLine
                    write(" + " & line & " / R$ " & Math.Round(line * p.btc, 2), white, black, 1, 0, True)
                End While
            End Using
            pause()
        Catch ex As Exception
            Console.WriteLine("wrong filename")
            pause()
        End Try
    End Function

    'print stored data
    Function vstored()
        clear()
        wsize(30, 60)
        Dim line As String
        write("current stored entry list", yellow, black, 1, 0)
        Using reader As New System.IO.StreamReader("data\37159")
            While Not reader.EndOfStream
                Console.BufferHeight += 1
                line = reader.ReadLine
                write(" + " & line & " / R$ " & Math.Round(line * p.btc, 2), white, black, 1, 0, True)
            End While
        End Using
        pause()
    End Function

    'days
    Function days()
        Dim l1 = System.IO.File.ReadAllLines("data\37157").Length - 1
        Dim l2 As Decimal = Math.Round(l1 / 6, 1)
        Return l2
    End Function

    'sum file data
    Function sumv()
        Dim vl As Decimal
        Using reader As New System.IO.StreamReader("data\37157")
            While Not reader.EndOfStream
                vl += reader.ReadLine
            End While
        End Using
        Return vl
    End Function

    'days since day0
    Function days2()
        Dim l1 = System.IO.File.ReadAllLines("data\37157").Length - 1
        Dim l2
        If System.IO.File.Exists("data\37159") Then
            l2 = System.IO.File.ReadAllLines("data\37159").Length - 1
        End If
        Dim l3 = l1 + l2
        Dim l5 As Decimal = Math.Round(l3 / 6, 1)
        Return l5
    End Function

    'sum all file data
    Function sumv2()
        Dim v1 As Decimal
        Using reader As New System.IO.StreamReader("data\37157")
            While Not reader.EndOfStream
                v1 += reader.ReadLine
            End While
        End Using
        Dim v2 As Decimal
        If System.IO.File.Exists("data\37159") Then
            Using reader As New System.IO.StreamReader("data\37159")
                While Not reader.EndOfStream
                    v2 += reader.ReadLine
                End While
            End Using
        End If
        Dim v3 As Decimal = v1 + v2
        Return v3
    End Function

    'displays graphs of stored data
    Function graph1()
        clear()
        wsize(30, 60)
        write("graph", yellow, black, 1, 0)
        write("", white, black, 2, 0)
        'todo?
        pause()
    End Function

End Module
