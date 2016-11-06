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

            // Main loop
            while (true)
            {
                // Establish objects necessary to manipulate the connection
                var client = _robotListener.AcceptTcpClient();
                var writer = new StreamWriter(client.GetStream()) { AutoFlush = true };
                Console.WriteLine("Robot connection established");
                var webClient = _webListener.AcceptTcpClient();
                var reader = new StreamReader(webClient.GetStream());
                string input;

                // Listening sub-loop
                while (true)
                {
                    try
                    {
                        input = reader.ReadLine();
                    }
                    catch (Exception)
                    {
                        Console.WriteLine("Robot connection error, listening for a new connection");
                        break;
                    }

                    if (input == null) continue;

                    var inputTokenArray = input.Split(' ');

                    // Ensure that incoming data matches protocol spec
                    // Switch is used here because it implements a hash table at 5+ cases 
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

        /// <summary>
        /// Initializes our listeners and sets them to listening
        /// </summary>
        private static void Initialize()
        {
            _webListener = new TcpListener(IPAddress.Any, 9000);
            _robotListener = new TcpListener(IPAddress.Any, 9001);

            _webListener.Start();
            _robotListener.Start();
        }
    }
}
