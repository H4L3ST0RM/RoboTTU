using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Summary description for WebProtocol
/// </summary>
public static class WebProtocol
{
    public static class Commands
    {
        public static string Forward = "FORWARD";
        public static string Reverse = "REVERSE";
        public static string TurnLeft = "TURNLEFT";
        public static string TurnRight = "TURNRIGHT";
        public static string ObstacleAvoidance = "AVOIDANCE";
        public static string ImageRecognition = "RECOGNITION";
        public static string Stream = "STREAM";
    }

    public static class Values
    {
        public static int Default = 5;
        public static int On = 1;
        public static int Off = 0;
    }
}

