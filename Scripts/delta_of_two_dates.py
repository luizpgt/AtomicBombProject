from datetime import datetime
from zoneinfo import ZoneInfo

# define timezone
sp = ZoneInfo("America/Sao_Paulo")

# two datetimes in São Paulo timezone
dt1 = datetime(2025, 1, 1, 14, 30, tzinfo=sp)
dt2 = datetime(2025, 8, 22, 10, 0, tzinfo=sp)

# compute difference
delta = dt2 - dt1

print("Days:", delta.days)
print("Total seconds:", delta.total_seconds())

