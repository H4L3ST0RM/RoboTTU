using System;
using System.IO;
using System.Net;
using System.Net.Sockets;

namespace CS4365_Web_Service
{
    internal class Program
    {
        private static TcpListener _webListener;
        private static TcpListener _robotListener;

        private static void Main()
        {
            Initialize();

            while (true)
            {
                var client = _robotListener.AcceptTcpClient();
                var stream = client.GetStream();

                var reader = new StreamReader(stream);
                var writer = new StreamWriter(stream);
                string input;

                writer.WriteLine("FORWARD");
                writer.Flush();

                while (client.Connected && (input = reader.ReadLine()) != null)
                {
                    Console.WriteLine(input);
                }
            }
        }

        private static void Initialize()
        {
            _webListener = new TcpListener(IPAddress.Any, 9000);
            _robotListener = new TcpListener(IPAddress.Any, 9001);

            _webListener.Start();
            _robotListener.Start();
        }
    }
}
