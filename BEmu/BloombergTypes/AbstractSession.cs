using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Bloomberglp.Blpapi
{
    public abstract class AbstractSession : IDisposable
    {
        public enum StopOption
        {
            SYNC,
            ASYNC,
        }

        public void Dispose()
        {
        }
    }
}
