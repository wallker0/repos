'help.vb
'credits to @wallker



Module help

    'help menu
    Function help1()
        clear()
        wsize(28, 60)
        write("help list                                                   ", black, yellow, 1, 0)
        write("in, new, add - to type a new deposit entry", white, black, 3, 0)
        write("out, del, deb - to type a new debit entry", white, black, 4, 0)
        write("store - to store data and reset entrys", white, black, 5, 0)
        write("view entrys, ins - to display a list of entrys", white, black, 6, 0)
        write("view recalls, outs - to display a list of pullouts", white, black, 7, 0)
        write("view price - to display btc price", white, black, 8, 0)
        write("view pwr - to display monthly power cost", white, black, 9, 0)
        write("list, list data - to display stored data", white, black, 10, 0)
        write("avrg - to display data average", white, black, 11, 0)
        write("lavrg - to display brute data average", white, black, 12, 0)
        write("open nh, nh - to open nicehash my rigs web page", white, black, 13, 0)
        write("open mbtc, mbtc - to open merc btc web page", white, black, 14, 0)
        write("open biz, biz - to open 4chan /biz/ web page", white, black, 15, 0)
        write("set id - to edit callID", white, black, 16, 0)
        write("set btc price, price - to edit btc price", white, black, 17, 0)
        write("set addr - to edit btc wallet address", white, black, 18, 0)
        write("set pwr - to edit monthly power cost", white, black, 19, 0)
        write("create key, key - to create a key file inside ..\data\", white, black, 20, 0)
        write("save - to manually save to ..\data\", white, black, 21, 0)
        write("reset - to delete ..\data\", white, black, 22, 0)
        write("quit - to safely exit", white, black, 23, 0)
        pause()
    End Function

End Module