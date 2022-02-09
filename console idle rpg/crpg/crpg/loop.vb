Imports System
Imports System.Object
Imports System.MarshalByRefObject
Imports System.Globalization
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.Collections
Imports System.Windows.Forms
Imports System.ComponentModel



Module loops
    Function loop1()
        Console.Clear()
        idling = 1
        Dim r As Random = New Random
        Dim processinfo = "crpgform.exe"
        Process.Start(processinfo)
        Console.SetCursorPosition(0, 10)
        Console.WriteLine("idling started, starting battles..")
        Do

            p.mhpt = r.Next(p.hpt, p.hpt * 10)
            p.mhpa = p.mhpt

            Do
                p.danototal = p.dano + r.Next(1, 101)
                p.mdmg = r.Next(p.danototal - 30, p.danototal + 80)
                p.heal = r.Next(p.mdmg - 20, p.mdmg + 70)
                Dim rbonus = r.Next(1, 25)
                Dim rbonus2 = r.Next(6, 10)

                p.mhpa -= p.danototal
                p.hpa -= p.mdmg
                p.xpa += r.Next(1, 20)

                If rbonus = rbonus2 Then
                    Dim bonus = r.Next(0, 5)
                    If bonus = 1 Then
                        Dim xpbonus = r.Next(600, 5000)
                        p.xpa += xpbonus
                        Console.ForegroundColor = ConsoleColor.Magenta
                        Console.WriteLine($"you gained a xp bonus: [ {xpbonus} ]")
                        Console.WriteLine()
                        System.Threading.Thread.Sleep(500)
                    End If
                    If bonus = 2 Then
                        Dim cashbonus = r.Next(50, 500)
                        p.cash += cashbonus
                        Console.ForegroundColor = ConsoleColor.Magenta
                        Console.WriteLine($"you gained a cash bonus: [ {cashbonus} ]")
                        Console.WriteLine()
                        System.Threading.Thread.Sleep(500)
                    End If
                    If bonus = 3 Then
                        Dim hpbonus = r.Next(300, 1000)
                        p.hpt += hpbonus
                        Console.ForegroundColor = ConsoleColor.Magenta
                        Console.WriteLine($"you gained an hp bonus: [ {hpbonus} ]")
                        Console.WriteLine()
                        System.Threading.Thread.Sleep(500)
                    End If
                    If bonus = 4 Then
                        Dim dmgbonus = r.Next(40, 90)
                        p.dano += dmgbonus
                        Console.ForegroundColor = ConsoleColor.Magenta
                        Console.WriteLine($"you gained a damage bonus: [ {dmgbonus} ]")
                        Console.WriteLine()
                        System.Threading.Thread.Sleep(500)
                    End If
                End If

                If (p.hpa < p.hpt) Then
                    p.hpa += p.heal
                End If

                If (p.hpa > p.hpt) Then
                    p.hpa = p.hpt
                End If

                If (p.xpa > p.xpt) Then
                    p.level += 1
                    p.xpt = p.xpt * 2
                    p.dano += r.Next(80, 221)
                    p.hpt += r.Next(400, 1000)
                    Console.ForegroundColor = ConsoleColor.Magenta
                    Console.WriteLine($"c o n g r a t s ! !   you reached a new level [ {p.level} ]")
                    Console.WriteLine()
                    System.Threading.Thread.Sleep(1000)
                End If

                Console.ForegroundColor = ConsoleColor.Red
                Console.WriteLine($"mob hp :  [{p.mhpa} / {p.mhpt}]")
                Console.WriteLine($"you took [ {p.mdmg} ] damage from [ 1 ] mob")

                Console.ForegroundColor = ConsoleColor.DarkGreen
                Console.Write($"hp: [{p.hpa} / {p.hpt}]")

                Console.ForegroundColor = ConsoleColor.Cyan
                Console.Write($"  xp: [{p.xpa} / {p.xpt}]")

                Console.ForegroundColor = ConsoleColor.Gray
                Console.Write($"  level: [{p.level}]")

                Console.ForegroundColor = ConsoleColor.Green
                Console.WriteLine()
                Console.WriteLine($"you did [ {p.danototal} ] damage to [ 1 ] mob")
                Console.WriteLine($"you got healed by [ {p.heal} ] hp")
                Console.WriteLine()

                Try
                    Dim sw As StreamWriter = New StreamWriter("saves\crpg1.dat")
                    x.Serialize(sw, p)
                    sw.Close()
                Catch ex As Exception
                    System.Threading.Thread.Sleep(500)
                    Dim sw As StreamWriter = New StreamWriter("saves\crpg1.dat")
                    x.Serialize(sw, p)
                    sw.Close()
                End Try


                Console.WriteLine()

                If Console.KeyAvailable Then
                    If Console.ReadKey(True).KeyChar = "q"c Then idling = 0
                End If

                System.Threading.Thread.Sleep(700)

            Loop Until idling = 0 Or p.mhpa <= 0

            If idling = 0 Then
                Console.ForegroundColor = ConsoleColor.Magenta
                Console.WriteLine($"API stopped..")
                System.Threading.Thread.Sleep(1000)
            Else
                Console.WriteLine($"c o n g r a t s ! !   you killed [ 1 ] enemy - Reward: [{p.mhpt / 10}] xp")
                Console.WriteLine()
                System.Threading.Thread.Sleep(1000)
                p.xpa += p.mhpt / 10
            End If

        Loop Until idling = 0
    End Function
End Module
