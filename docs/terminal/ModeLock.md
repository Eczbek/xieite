# [xieite](../../README.md)::[terminal](../terminal.md)::ModeLock
Defined in header [<xieite/terminal/ModeLock.hpp>](../../include/xieite/terminal/ModeLock.hpp)

<br/>

A lock-style class for toggling terminal settings

<br/><br/>

## Synopsis

<br/>

```cpp
struct ModeLock final {
	ModeLock();

	~ModeLock();

	void setBlocking(bool);

	void setEcho(bool);

	void setCanonical(bool);

	void setSignals(bool);

	void setProcessing(bool);

	void lock();

	void unlock();

	bool isLocked() const;
}
```
### Public members
<pre><code>ModeLock/
|- <a href="./ModeLock/constructor.md">ModeLock</a>
|- <a href="./ModeLock/destructor.md">~ModeLock</a>
|- <a href="./ModeLock/setBlocking.md">setBlocking</a>
|- <a href="./ModeLock/setEcho.md">setEcho</a>
|- <a href="./ModeLock/setCanonical.md">setCanonical</a>
|- <a href="./ModeLock/setSignals.md">setSignals</a>
|- <a href="./ModeLock/setProcessing.md">setProcessing</a>
|- <a href="./ModeLock/lock.md">lock</a>
|- <a href="./ModeLock/unlock.md">unlock</a>
`- <a href="./ModeLock/isLocked.md">isLocked</a>
</code></pre>
