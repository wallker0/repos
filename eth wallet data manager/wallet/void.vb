'void.vb
'credits to @wallker



Module void

    'savefile
    Function save()
        'p.weth = sumv()
        Dim sw As System.IO.StreamWriter = New System.IO.StreamWriter("data\37156.eth")
        x.Serialize(sw, p)
        sw.Close()
        write("d o n e !", yellow, black, 4, 30)
        s(250, 5, 30)
        clear()
    End Function


    'import
    Function import()
        Using sr As New System.IO.StreamReader("data\37156.eth")
            p = x.Deserialize(sr)
        End Using
        index = 1
        clear()
    End Function


    'firstrun
    Function firstrun()
        clear()
        System.IO.Directory.CreateDirectory("data\")
        If Not System.IO.File.Exists("data\37157.eth") Then System.IO.File.Create("data\37157.eth").Dispose()
        If Not System.IO.File.Exists("data\37158.eth") Then System.IO.File.Create("data\37158.eth").Dispose()
        writeto("data\37157.eth", 0)
        writeto("data\37158.eth", 0)
        Dim rand As Random = New Random
        write("callID ? : ", yellow, black, 1, 2)
        p.name = Console.ReadLine()
        p.addr = "0xe"
        clear()
        p.pwr = 0
        p.eth = 0
        x.Serialize(Console.Out, p)
        pause()
        save()
        index = 1
        clear()
    End Function


    'freset
    Function freset()
        clear()
        write("reset everything ? ( yes / no ) : ", yellow, black, 1, 0)
        Dim resp = Console.ReadLine()
        If resp = "yes" Then
            clear()
            write("ok..", yellow, black, 1, 0)
            Dim txtList As String() = System.IO.Directory.GetFiles("data\", "*.*")
            For Each f As String In txtList
                System.IO.File.Delete(f)
            Next
            p.eth = 0
            p.weth = 0
            System.Threading.Thread.Sleep(1000)
            main1()
        Else End If
    End Function


    'edit name
    Function ename()
        clear()
        write($"new name? old [ {p.name} ] : ", yellow, black, 1, 0)
        p.name = Console.ReadLine()
        save()
    End Function


    'view btc price
    Function vbtc()
        clear()
        write($"ether price : R$ {p.eth},00", yellow, black, 1, 0)
        pause()
    End Function


    'view pwr cost
    Function vpwr()
        clear()
        write($"monthly power cost : R$ {p.pwr},00", yellow, black, 1, 0)
        pause()
    End Function


    'edit btc price
    Function ebtc()
        clear()
        write("ether price : ", yellow, black, 1, 0)
        p.eth = Console.ReadLine()
        save()
    End Function


    'edit pwr cost
    Function epwr()
        clear()
        write("monthly pwr cost : ", yellow, black, 1, 0)
        p.pwr = Console.ReadLine()
        save()
    End Function


    'edit btc adr
    Function eaddr()
        clear()
        write("ether addr: ", yellow, black, 1, 0)
        p.addr = Console.ReadLine()
        save()
    End Function


    'create key
    Function dkey()
        clear()
        If Not System.IO.File.Exists("data\" & p.addr) Then System.IO.File.Create("data\" & p.addr).Dispose()
        writeto("data\" & p.addr, p.addr)
        save()
    End Function


End Module
