using System;
using System.IO;
using System.Net.Sockets;

public partial class RoboTTU : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void btnForward_Click(object sender, EventArgs e)
    {
        SendCommand(WebProtocol.Commands.Forward, WebProtocol.Values.Default);
    }

    protected void btnReverse_Click(object sender, EventArgs e)
    {
        SendCommand(WebProtocol.Commands.Reverse, WebProtocol.Values.Default);
    }

    protected void btnTurnLeft_Click(object sender, EventArgs e)
    {
        SendCommand(WebProtocol.Commands.TurnLeft, WebProtocol.Values.Default);
    }

    protected void btnTurnRight_Click(object sender, EventArgs e)
    {
        SendCommand(WebProtocol.Commands.TurnRight, WebProtocol.Values.Default);
    }

    protected void btnAvoidance_Click(object sender, EventArgs e)
    {
        SendCommand(WebProtocol.Commands.ObstacleAvoidance, WebProtocol.Values.Default);
    }
    protected void btnRecognition_Click(object sender, EventArgs e)
    {
        SendCommand(WebProtocol.Commands.ImageRecognition, WebProtocol.Values.Default);
    }
    protected void btnStreamOn_Click(object sender, EventArgs e)
    {
        SendCommand(WebProtocol.Commands.Stream, WebProtocol.Values.On);
    }
    protected void btnStreamOff_Click(object sender, EventArgs e)
    {
        SendCommand(WebProtocol.Commands.Stream, WebProtocol.Values.Off);
    }

    private void SendCommand(string command, int value)
    {
        try
        {
            using (var client = new TcpClient("127.0.0.1", 9000))
            using (var writer = new StreamWriter(client.GetStream()) {AutoFlush = true})
            {
                writer.WriteLine($"{command} {value}");
                client.Close();
            }
        }
        catch
        {
            lblStatus.Text = "Error: Could not connect to web service";
        }
        lblStatus.Text = string.Empty;
    }
}