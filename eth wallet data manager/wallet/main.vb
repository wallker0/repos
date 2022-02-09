'main.vb
'credits to @wallker



Module main

    'preload
    Sub main()

        If fileexists("data\37156.eth") = False Then
            firstrun()
        Else
            import()
        End If

        'If Not sumv() = p.weth Then
        'write("data corrupted", red, black, 1, 3)
        'pause()
        'Exit Sub
        'End If

        main1()

    End Sub

End Module
