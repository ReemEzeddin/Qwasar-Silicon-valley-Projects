def my_is_sort(param_1)
    tstart = Time.now
    1000000.times {
        param_1.sort
    }
    trun = Time.now - tstart

    param_1.sort!
    tstart = Time.now
    1000000.times {
        param_1.sort
    }
    treference = Time.now - tstart

    if trun > treference
      return true
    else
        return false
    end
end