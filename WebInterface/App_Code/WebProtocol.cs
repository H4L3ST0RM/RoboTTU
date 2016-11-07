﻿using System;
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
        public static string CameraLeft = "CAMERALEFT";
        public static string CameraRight = "CAMERARIGHT";
    }

    public static class Values
    {
        public static int Default = 5;
    }
}
