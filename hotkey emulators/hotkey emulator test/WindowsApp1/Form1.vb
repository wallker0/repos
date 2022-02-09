Option Explicit On


Public Class form

    Dim prc() As Process
    Dim ind As Integer


    Function check()
        prc = Process.GetProcessesByName("notepad")
        If prc.Count > 0 Then
            ' Process is running
            ind = 1
        Else
            ' Process is not running
            Button1.Enabled = False
            Button2.Enabled = False
            Button3.Enabled = False
            Button4.Enabled = False
            Button5.Enabled = False
            Button6.Enabled = False
            ind = 0
            main()
        End If
    End Function

    Function send(key As String)
        check()
        SendKeys.Send("{" + key + "}")
    End Function

    Sub main()

        While ind = 0
            check()
        End While

    End Sub


    Private Sub Button7_Click(sender As Object, e As EventArgs) Handles Button7.Click
        Close()
    End Sub

    Sub form_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        main()
    End Sub

    Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        send(1)
    End Sub

    Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        send(2)
    End Sub

    Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        send(3)
    End Sub

    Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        send(4)
    End Sub

    Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        send(5)
    End Sub

    Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        send(6)
    End Sub

    Sub Button8_Click(sender As Object, e As EventArgs) Handles Button8.Click
        MessageBox.Show("processo para emular o pressionamento de teclas por botao..")
    End Sub

End Class
