'cvar.vb
'credits to @wallker





Imports System.Globalization

Imports System.Object
Imports System.MarshalByRefObject
Imports System.IO
Imports System.Xml
Imports System.Drawing
Imports System.ComponentModel.Component
Imports System.Net.WebClient


Public Class cvar1

    Public selec1 As Boolean = False 'switch on/off
    Public selec2 As Boolean = False 'switch on/off

    Public selec3 As Boolean = False 'switch on/off
    Public selec4 As Boolean = False 'switch on/off

    Public selec5 As Boolean = False 'switch on/off

    Public selec6 As Boolean = False 'option
    Public selec7 As Boolean = False 'option
    Public selec8 As Boolean = False 'on/off


    Public file1 As Boolean = False
    Public file2 As Boolean = False
    Public file3 As Boolean = False
    Public file4 As Boolean = False
    Public file5 As Boolean = False
    Public file6 As Boolean = False

    Public file7 As Boolean = False
    Public file8 As Boolean = False

End Class



Public Class cvar2

    Public nome As String
    Public telef As String
    Public ender As String
    Public valor As String
    Public pgo As String

End Class



Public Class cvar3

    Public nome As String
    Public valor As String
    Public data As String

End Class