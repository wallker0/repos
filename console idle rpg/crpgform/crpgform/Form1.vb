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

Public Class Form1

    Dim p As New cvar()
    Dim x As New Xml.Serialization.XmlSerializer(p.GetType)
    Dim index As Integer

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

    Function save()
        Try
            Dim sw As StreamWriter = New StreamWriter("saves\crpg1.dat")
            x.Serialize(sw, p)
            sw.Close()
        Catch ex As Exception
            System.Threading.Thread.Sleep(500)
        End Try
    End Function

    Dim prc() As Process

    Private Sub check()
        prc = Process.GetProcessesByName("crpg")
        If prc.Count > 0 Then
            ' Process is running
        Else
            ' Process is not running
            Close()
        End If
    End Sub

    Public Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        If FileExists("saves\crpg1.dat") = False Then
            Close()
        End If

        Timer1.Start()

    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Try
            check()

            Using sr As New StreamReader("saves\crpg1.dat")
                p = x.Deserialize(sr)
                sr.Close()
            End Using

            ProgressBar1.Maximum = p.hpt     'hp char
            ProgressBar2.Maximum = p.xpt     'xp char
            ProgressBar4.Maximum = p.mhpt    'hp bot
            ProgressBar3.Maximum = 100       'progress

            ProgressBar1.Minimum = 0
            ProgressBar2.Minimum = 0
            ProgressBar4.Minimum = 0
            ProgressBar3.Minimum = 0

            ProgressBar1.ForeColor = Color.Red
            ProgressBar2.ForeColor = Color.Cyan
            ProgressBar4.ForeColor = Color.Red
            ProgressBar3.ForeColor = Color.Cyan

            ProgressBar1.Value = p.hpa
            ProgressBar2.Value = p.xpa
            ProgressBar4.Value = p.mhpa

            ProgressBar1.Refresh()
            ProgressBar2.Refresh()
            ProgressBar4.Refresh()
            ProgressBar3.Refresh()

            Dim pHP As Integer = (p.hpa / p.hpt) * 100
            Dim pXP As Integer = (p.xpa / p.xpt) * 100
            Dim mHP As Integer = (p.mhpa / p.mhpt) * 100
            Dim progr As Integer = (100 - mHP)

            If ProgressBar3.Value = ProgressBar3.Maximum Then
                ProgressBar3.Value = 0
            End If

            ProgressBar3.Value = progr

            Label3.Text = p.heal
            Label9.Text = pHP & "%"
            Label10.Text = pXP & "%"
            Label11.Text = p.level
            Label12.Text = p.danototal
            Label18.Text = p.cash

            Label15.Text = mHP & "%"
            Label13.Text = p.mdmg

        Catch ex As Exception
            System.Threading.Thread.Sleep(500)
        End Try

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim r As Random = New Random
        Dim heal = r.Next(400, 1400)

        Try
            If p.hpa < p.hpt Then
                p.hpa += heal
                save()
            End If

            If p.hpa > p.hpt Then
                p.hpa = p.hpt
                save()
            End If

        Catch ex As Exception
            System.Threading.Thread.Sleep(500)
        End Try

    End Sub
End Class
