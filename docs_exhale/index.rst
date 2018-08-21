Testing With Exhale and Breathe
===============================

.. toctree::
   :maxdepth: 2

   api/library_root

Link Testing
============

Traditional Links
-----------------

Old way of linking always works:

- ``simgrid::s4u::Actor::kill`` links correctly: :cpp:func:`simgrid::s4u::Actor::kill`

New Overload Links for Sphinx v1.8
----------------------------------

Explicit Overload v1
++++++++++++++++++++

- ``void simgrid::s4u::Actor::kill()``: :cpp:func:`void simgrid::s4u::Actor::kill()`

This one on its own (comment out Explicit Overload v2 bullet point below) triggers a
build warning about ``unabridged_api.rst`` not being included in any toctree.  This is
technically correct because the generated ``library_root.rst`` looks like this:

.. code-block:: rst

   Library API
   ===========

   .. include:: class_view_hierarchy.rst

   .. include:: file_view_hierarchy.rst

   .. include:: unabridged_api.rst

Like in the next section, this warning occurs on every other build (make sure you
comment out the bullet point in the Explicit Overload v2 section to observe this).

Unlike the next section, once you build a second time, all subsequent builds will
produce this warning.  So if you ``make clean`` and then ``make html``, it will build
without warnings, but the next ``make html`` will produce the warning about
``unabridged_api.rst`` not being included in any toctree.

Explicit Overload v2
++++++++++++++++++++

- ``void simgrid::s4u::Actor::kill(aid_t)``: :cpp:func:`void simgrid::s4u::Actor::kill(aid_t)`

Every other build will fail on this.

1. Run ``make html`` once, and it will succeed.
2. Run ``make html`` again, without changing anything, and it will fail:

.. code-block:: py3tb

     File "/home/sven/Desktop/sphinx-cpp-cross-ref-bug/docs_exhale/venv/lib/python2.7/site-packages/sphinx/domains/cpp.py", line 4170, in find_declaration
       candId = symbol.declaration.get_newest_id()
   AttributeError: 'NoneType' object has no attribute 'get_newest_id'

The full log for this specific error:

.. literalinclude:: sphinx-err-h4me3j.log
   :language: none
