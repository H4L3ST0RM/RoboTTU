using System;
using System.Net.Sockets;

namespace RoboTTU
{
    public partial class RoboTTU : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnTurnLeft_Click(object sender, EventArgs e)
        {
            
        }

        private void SendCommand(string command, int value)
        {
            using (TcpClient client = new TcpClient("127.0.0.1", 9000))
            {
                //client
            }
        }
    }
}