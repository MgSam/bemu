//------------------------------------------------------------------------------
// <copyright project="BEmu_csh" file="BloombergTypes/SessionOptions.cs" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------

namespace Bloomberglp.Blpapi
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;

    public class SessionOptions
    {
        public string ServerHost { get; set; }
        public int ServerPort { get; set; }

        public bool AutoRestartOnDisconnection { get; set; }
        public bool KeepaliveEnabled { get; set; }
        public int ConnectTimeout { get; set; }
        public int MaxPendingRequests { get; set; }
        public int MaxEventQueueSize { get; set; }
        public int MaxOutstandingRequests { get; set; }
        public int NumStartAttempts { get; set; }
        public ServerAddress[] ServerAddresses { get; set; }
        public string AuthenticationOptions { get; set; }
        public int MaxSendCacheSize { get; set; }
        public bool AllowMultipleCorrelatorsPerMsg { get; set; }
        public float SlowConsumerWarningHiWaterMark { get; set; }
        public float SlowConsumerWarningLoWaterMark { get; set; }
        public string DefaultSubscriptionService { get; set; }
        public string DefaultTopicPrefix { get; set; }
        public ClientModeType ClientMode { get; set; }
        public int DefaultKeepAliveInactivityTime { get; set; }
        public int DefaultKeepAliveResponseTimeout { get; set; }
        public bool RecordSubscriptionDataReceiveTimes { get; set; }
        public SessionOptions() { }

        public enum ClientModeType
        {
            AUTO,
            DAPI,
            SAPI,
        }

        public class ServerAddress
        {
            public string Host { get; set; }
            public int Port { get; set; }

            public ServerAddress(string host, int port)
            {
                Host = host;
                Port = port;
            }

            public override string ToString()
            {
                return Host + ":" + Port;
            }
        }
    }
}
