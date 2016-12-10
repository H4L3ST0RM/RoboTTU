<%@ Page Language="C#" AutoEventWireup="true" CodeFile="RoboTTU.aspx.cs" Inherits="RoboTTU" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <asp:ScriptManager runat="server" />
        <asp:Table ID="tblMain" Width="75%" HorizontalAlign="Center" runat="server" Font-Names="Calibri" CellSpacing="5">
            <asp:TableRow HorizontalAlign="Center">
                <asp:TableCell ColumnSpan="2">
                    <iframe width="640" height="480" src="https://www.youtube.com/embed/live_stream?channel=UCci5U62GUrWc6Ax90f2Wmnw&autoplay=1"></iframe>
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow HorizontalAlign="Center">
                <asp:TableCell ColumnSpan="2">Movement Controls</asp:TableCell>
            </asp:TableRow>
            <asp:TableRow HorizontalAlign="Center">
                <asp:TableCell HorizontalAlign="Right" Width="50%">
                    <asp:UpdatePanel runat="server">
                        <ContentTemplate>
                            <asp:Button ID="btnTurnLeft" Text="Left" OnClick="btnTurnLeft_Click" runat="server" />&nbsp;
                            <asp:Button ID="btnForward" Text="Forward" OnClick="btnForward_Click" runat="server"/>
                        </ContentTemplate>
                    </asp:UpdatePanel>
                </asp:TableCell>
                <asp:TableCell HorizontalAlign="Left">
                    <asp:UpdatePanel runat="server">
                        <ContentTemplate>
                            <asp:Button ID="btnReverse" Text="Reverse" OnClick="btnReverse_Click" runat="server"/>&nbsp;
                            <asp:Button ID="btnTurnRight" Text="Right" OnClick="btnTurnRight_Click" runat="server"/>
                        </ContentTemplate>
                    </asp:UpdatePanel>
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow HorizontalAlign="Center">
                <asp:TableCell ColumnSpan="2">Other Controls</asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell HorizontalAlign="Right" Width="50%">
                    <asp:UpdatePanel runat="server">
                        <ContentTemplate>
                            <asp:Button ID="btnAvoidance" Text="Obstacle Avoidance" OnClick="btnAvoidance_Click" runat="server"/>
                        </ContentTemplate>
                    </asp:UpdatePanel>
                </asp:TableCell>
                <asp:TableCell HorizontalAlign="Left">
                    <asp:UpdatePanel runat="server">
                        <ContentTemplate>
                            <asp:Button ID="btnRecognition" Text="Image Recognition" OnClick="btnRecognition_Click" runat="server"/>
                        </ContentTemplate>
                    </asp:UpdatePanel>
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow runat="server">
                <asp:TableCell ID="lblStatus" HorizontalAlign="Center" runat="server" ColumnSpan="2"></asp:TableCell>
            </asp:TableRow>
        </asp:Table>
    </form>
</body>
</html>