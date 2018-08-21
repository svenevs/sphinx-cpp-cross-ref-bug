# sphinx-cpp-cross-ref-bug

Demo repo trying to diagnose how these errors occur using the new Sphinx C++ Domain
function overload cross-ref syntax.  See the
[Overloaded (member) functions](http://www.sphinx-doc.org/en/master/usage/restructuredtext/domains.html#overloaded-member-functions)
section of the Sphinx C++ Domain documentation for more information.  The links we are
interested in here are the ones that include the return type and possible function
parameters.

## Test Cases

There are three test cases, you should use a `virtualenv` to keep them isolated.

```console
$ pip install virtualenv
```

or use your system package manager.

### `docs_exhale`

```console
$ cd docs_exhale

# must be called `venv`, conf.py ignores that specifically
$ virtualenv venv
$ source venv/bin/activate
$ pip install -r requirements.txt

# success on first run
$ make html

# failure on second run
$ make html

# success on third run
$ make html

# ... every other execution will fail ...
```

Read the generated website in `docs_exhale/_build/html/index.html` for a full
description, using the new Sphinx C++ Overload cross-ref targets introduces two
strange bugs:

1. `void simgrid::s4u::Actor::kill()` triggers a warning about the generated
   `unabridged_api.rst` file not being included in any `toctree`.
2. `void simgrid::s4u::Actor::kill(aid_t)`: every other build will fail with this
   target being referenced.

### `docs_breathe`

```console
# make sure to `deactivate` if you are in the `venv` from docs_exhale!
$ cd docs_breathe

# must be called `venv`, conf.py ignores that specifically
$ virtualenv venv
$ source venv/bin/activate
$ pip install -r requirements.txt

# success on first run
$ make html

# failure on second run
$ make html

# success on third run
$ make html

# ... every other execution will fail ...
```

Read the generated website in `docs_breathe/_build/html/index.html` for a full
description, using the new Sphinx C++ Overload cross-ref targets introduces
a strange bug:

- `void simgrid::s4u::Actor::kill(aid_t)`: every other build will fail with this
  target being referenced.

### `docs_just_sphinx`

```console
# make sure to `deactivate` if you are in the `venv` from docs_breathe!
$ cd docs_just_sphinx

# must be called `venv`, conf.py ignores that specifically
$ virtualenv venv
$ source venv/bin/activate
$ pip install -r requirements.txt

# always successful
$ make html
```

This is just included for completeness.  What's worth noting is that both the pure
Sphinx C++ domain and the Breathe directives create the same mangled names:

- `void Actor::kill()`
    - Sphinx C++ Domain: `_CPPv3N7simgrid3s4u5Actor4killEv`
    - Breathe Directive: `_CPPv3N7simgrid3s4u5Actor4killEv`
- `static void Actor::kill(aid_t)`
    - Sphinx C++ Domain: `_CPPv3N7simgrid3s4u5Actor4killE5aid_t`
    - Breathe Directive: `_CPPv3N7simgrid3s4u5Actor4killE5aid_t`

Therefore, this appears to be a Sphinx bug?  It's very confusing how this happens...
