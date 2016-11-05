﻿using System;
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
                var writer = new StreamWriter(stream) { AutoFlush = true };
                string input;

                while (client.Connected && (input = reader.ReadLine()) != null)
                {
                    var inputTokenArray = input.Split(' ');

                    switch (inputTokenArray[0])
                    {
                        case "FORWARD":
                        case "BACKWARD":
                        case "TURNLEFT":
                        case "TURNRIGHT":
                        case "CAMERALEFT":
                        case "CAMERARIGHT":
                            writer.WriteLine($"{inputTokenArray[0]} {inputTokenArray[1]}");
                            Console.WriteLine($"Processed {inputTokenArray[0]} command");
                            break;
                        default:
                            break;
                    }

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
