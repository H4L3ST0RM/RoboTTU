<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="RoboTTU.aspx.cs" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <asp:Table Width="75%" HorizontalAlign="Center" runat="server" Font-Names="Calibri" CellSpacing="5">
            <asp:TableRow HorizontalAlign="Center">
                <asp:TableCell ColumnSpan="2">
                    <iframe width="640" height="360" src="https://www.youtube.com/embed/Y-0ui7hXy_Q?autoplay=1"></iframe>
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow HorizontalAlign="Center">
                <asp:TableCell ColumnSpan="2">Tread Controls</asp:TableCell>
            </asp:TableRow>
            <asp:TableRow HorizontalAlign="Center">
                <asp:TableCell HorizontalAlign="Right" Width="50%">
                    <asp:Button ID="btnTurnLeft" Text="Turn Left" runat="server" />&nbsp;
                    <asp:Button ID="btnForward" Text="Forward" runat="server"/>
                </asp:TableCell>
                <asp:TableCell HorizontalAlign="Left">
                    <asp:Button ID="btnReverse" Text="Reverse" runat="server"/>&nbsp;
                    <asp:Button ID="btnTurnRight" Text="Right" runat="server"/>
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow HorizontalAlign="Center">
                <asp:TableCell ColumnSpan="2">Camera Controls</asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell HorizontalAlign="Right" Width="50%">
                    <asp:Button ID="btnCameraServoLeft" Text="Left" runat="server"/>
                </asp:TableCell>
                <asp:TableCell HorizontalAlign="Left">
                    <asp:Button ID="btnCameraServoRight" Text="Right" runat="server"/>
                </asp:TableCell>
            </asp:TableRow>
        </asp:Table>
    </form>
</body>
</html>
