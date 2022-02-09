'menu.vb
'credits to @wallker



Module menu

    Function main1()

        While index = 1

            clear()
            wsize(14, 60)
            bheight(14)
            bwidth(60)

            ctitle("w a l l e t")

            write($"welcome, {p.name}            [ date: {DateTime.Now} ] ", black, yellow, 0, 0)

            write(p.addr, white, black, 2, 0)
            write(p.weth, white, black, 4, 0)
            write("R$ " & Math.Round(p.eth * p.weth, 2), white, black, 5, 0)
            write(days2() & " day(s)", white, black, 7, 0)
            write("R$ " & Math.Round(sumv2() * p.eth, 2) & " total", white, black, 8, 0)

            write("------------------------------------------------------------", white, black, 10, 0)
            write("======== commands: edit %% | help | view %% | quit =========", black, yellow, 11, 0)
            write("------------------------------------------------------------", white, black, 12, 0)

            cpos(13, 0)
            txtcolor(yellow)

            Select Case Console.ReadLine()
                Case "in", "new", "add"
                    regnew()
                Case "out", "del", "deb"
                    debnew()
                Case "set id"
                    ename()
                Case "set price", "price"
                    ebtc()
                Case "set addr"
                    eaddr()
                Case "set pwr"
                    epwr()
                Case "view eth price", "view price"
                    vbtc()
                Case "view entrys", "entrys", "ins"
                    walletd()
                Case "view recalls", "recalls", "outs"
                    walletw()
                Case "view stored", "stored"
                    vstored()
                Case "view pwr"
                    vpwr()
                Case "list", "list data", "show data", "view data"
                    ldata()
                Case "avrg"
                    avrg()
                Case "lavrg"
                    lavrg()
                Case "graph"
                    graph1()
                Case "open ethermine", "ethermine"
                    open("https://ethermine.org/")
                Case "open nh", "nh"
                    open("https://www.nicehash.com/my/mining/rigs")
                Case "open mbtc", "mbtc"
                    open("https://www.mercadobitcoin.com.br/")
                Case "open biz", "biz"
                    open("https://www.4chan.org/biz/")
                Case "create key", "key"
                    dkey()
                Case "save"
                    save()
                Case "reset"
                    freset()
                Case "store"
                    store()
                Case "help"
                    help1()
                Case "quit", "exit", "leave"
                    save()
                    index = 0
                Case Else
                    clear()
            End Select

            If index = 0 Then
                Exit Function
            End If

        End While

    End Function

End Module
